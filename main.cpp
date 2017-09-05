#define STB_IMAGE_IMPLEMENTATION
#include "revork/revork.h"
//#include "../dep/universal/draw_text.h"

// GameObject sphere;
// GameObject cube;
unsigned int font;

int main() {
  Revork revork;
  revork.init();
  GameObject sphere;
  GameObject cube;
  sphere.shader.init();
  sphere.shader.load_from_file("../revork/res/shaders/gameobject/gameobject.vs");
  sphere.shader.load_from_file("../revork/res/shaders/gameobject/gameobject.fs");
  sphere.shader.bind_attrib(0, "position");
  sphere.shader.bind_attrib(1, "text_coord");
  sphere.shader.bind_attrib(2, "normal");
  sphere.shader.link();

  sphere.texture.init();
  sphere.texture.load_file("../revork/res/textures/container.jpg");
  sphere.texture.tex_parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  sphere.texture.tex_parameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
  sphere.texture.tex_parameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  sphere.texture.tex_parameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  sphere.texture.tex_parameter(GL_TEXTURE_MAX_LEVEL, 3);
  sphere.texture.end();

  sphere.mesh = Mesh("../revork/res/meshes/sphereUV.obj");

  cube.shader.init();
  cube.shader.load_from_file("../revork/res/shaders/gameobject/gameobject.vs");
  cube.shader.load_from_file("../revork/res/shaders/gameobject/gameobject.fs");
  cube.shader.bind_attrib(0, "position");
  cube.shader.bind_attrib(1, "text_coord");
  cube.shader.bind_attrib(2, "normal");
  cube.shader.link();

  cube.texture.init();
  cube.texture.load_file("../revork/res/textures/container.jpg");
  cube.texture.tex_parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  cube.texture.tex_parameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
  cube.texture.tex_parameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  cube.texture.tex_parameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  cube.texture.tex_parameter(GL_TEXTURE_MAX_LEVEL, 3);
  cube.texture.end();

  cube.mesh = Mesh("../revork/res/meshes/cubeUV.obj");

  cube.transform.pos.x += 5.0f;
  revork.add_gameobject(&sphere);
  revork.add_gameobject(&cube);

  const std::vector<std::string> faces
  {
      "../revork/res/skybox/default/right.jpg",
      "../revork/res/skybox/default/left.jpg",
      "../revork/res/skybox/default/top.jpg",
      "../revork/res/skybox/default/bottom.jpg",
      "../revork/res/skybox/default/back.jpg",
      "../revork/res/skybox/default/front.jpg"
  };
  revork.renderer.set_skybox(faces);

  //font_renderer::init();  
  //font = font_renderer::load_font("/System/Library/Fonts/LucidaGrande.ttc", 48);

  revork.run();
  revork.shutdown();
  //font_renderer::shutdown();
  
}