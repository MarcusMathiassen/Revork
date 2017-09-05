#pragma once


// compile with: -std=c++1z -I/usr/local/include/freetype2 -lfreetype -lglew -lglfw -framework OpenGL

#include <cassert>
#include <iostream>
#include <cctype>
#include <vector>
#include <array>
#include <map>
#include <string>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H

namespace font_renderer {

  struct Character {
      unsigned int TextureID;   // ID handle of the glyph texture
      glm::ivec2 Size;    // Size of glyph
      glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
      unsigned int Advance;    // Horizontal offset to advance to next glyph
  };

  struct Font {
    std::string name;
    int size;
    std::map<char, Character> characters;
  };


  static FT_Library ft;
  enum {VERTEX, INDICES, NUM_BUFFERS};
  static std::vector<Font> fonts;
  static unsigned int vao, vbo[NUM_BUFFERS], shader_program, text_color_location;

  static void shutdown() {
    fonts.clear();
    FT_Done_FreeType(ft);
  }
  static void init() {

    // Init shaders, buffers, and freetype2
    shader_program = glCreateProgram();
    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);

    const char* vert_source =
      "#version 330\n"
      "in vec4 vertex;\n"
      "out vec2 TexCoords;\n"
      "uniform mat4 ortho_projection;\n"
      "\n"
      "void main()\n"
      "{\n"
        "  gl_Position = ortho_projection * vec4(vertex.xy, 0.0, 1.0);\n"
       "   TexCoords = vertex.zw;\n"
      "}\n";

    const char* frag_source =
      "#version 330\n"
      "in vec2 TexCoords;\n"
      "out vec4 color;\n"
      "uniform sampler2D text;\n"
      "uniform vec4 text_color;\n"
      "void main()\n"
      "{\n"
      "    vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);\n"
      "    color = text_color * sampled;\n"
      "}\n";

    glShaderSource(vs, 1, &vert_source, NULL);
    glShaderSource(fs, 1, &frag_source, NULL);

    glCompileShader(vs);
    glCompileShader(fs);

    glAttachShader(shader_program, vs);
    glAttachShader(shader_program, fs);

    glLinkProgram(shader_program);
    glValidateProgram(shader_program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    const auto pos_attrib_loc = glGetAttribLocation(shader_program, "vertex");

    glGenVertexArrays(1, &vao);
    glGenBuffers(NUM_BUFFERS, vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[VERTEX]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 4 * 4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(pos_attrib_loc);
    glVertexAttribPointer(pos_attrib_loc, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);

    const std::uint16_t indices[6]{0, 1, 2, 0, 2, 3};
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[INDICES]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
                 GL_STATIC_DRAW);

    text_color_location = glGetUniformLocation(shader_program, "text_color");

    if (FT_Init_FreeType(&ft))
      std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
  }


  unsigned int load_font(const std::string &path_to_font, int size)
  {
    // our new Font
    Font font;

    // Load font as face
    FT_Face face;
    if (FT_New_Face(ft, path_to_font.c_str(), 0, &face))
        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

    // Set size to load glyphs as
    FT_Set_Pixel_Sizes(face, 0, size);

    // Disable byte-alignment restriction
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // Load first 128 characters of ASCII set
    for (GLubyte c = 0; c < 127; c++)
    {
      // Load character glyph
      if (FT_Load_Char(face, c, FT_LOAD_RENDER))
      {
          std::cout << "ERROR::FREETYTPE: Failed to load Glyph from file: " << path_to_font << std::endl;
          continue;
      }
      // Generate texture
      unsigned int texture;
      glGenTextures(1, &texture);
      glBindTexture(GL_TEXTURE_2D, texture);
      glTexImage2D(
          GL_TEXTURE_2D,
          0,
          GL_RED,
          face->glyph->bitmap.width,
          face->glyph->bitmap.rows,
          0,
          GL_RED,
          GL_UNSIGNED_BYTE,
          face->glyph->bitmap.buffer
      );
      // Set texture options
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      // Now store character for later use
      Character ch = {
          texture,
          glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
          glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
          static_cast<unsigned int>(face->glyph->advance.x)
      };
      font.characters.insert(std::pair<char, Character>(c, ch));
    }
    glBindTexture(GL_TEXTURE_2D, 0);

    // Destroy FreeType once we're finished
    FT_Done_Face(face);

    const auto id = fonts.size();

    // Add to the pile
    fonts.emplace_back(font);

    // Give the id back to the user
    return id;
  }

  void draw_text(unsigned int font_id, const std::string &text, float x, float y, float scale, const glm::vec4 &color)
  {
    // dont render 100% transparent text
    if (color.a < 0.005f) return;

    glUseProgram(shader_program);
    glUniform4f(text_color_location, color.r, color.g, color.b, color.a);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(vao);

    auto font = fonts[font_id];

    for (auto c = text.begin(); c != text.end(); ++c)
    {
      const Character ch = font.characters[*c];

      const float xpos = x + ch.Bearing.x * scale;
      const float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

      const float w = ch.Size.x * scale;
      const float h = ch.Size.y * scale;

      const float vertices[16] = {
          xpos,     ypos + h,   0.0, 0.0,
          xpos,     ypos,       0.0, 1.0,
          xpos + w, ypos,       1.0, 1.0,
          xpos + w, ypos + h,   1.0, 0.0
      };

      glBindTexture(GL_TEXTURE_2D, ch.TextureID);

      glBindBuffer(GL_ARRAY_BUFFER, vbo[VERTEX]);
      glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, NULL);

      // Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
      x += (ch.Advance >> 6) * scale; // Bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
    }
  }

} // namespace font_renderer
