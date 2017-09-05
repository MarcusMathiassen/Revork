#include "texture.h"

#include <cstdio>

#define GLEW_STATIC
#include <GL/glew.h>

void Texture::init()
{
  glGenTextures(1, &texture_id);
  glBindTexture(GL_TEXTURE_2D, texture_id);
}
void Texture::end()
{
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);  
  glGenerateMipmap(GL_TEXTURE_2D);
  stbi_image_free(image_data);
}
void Texture::load_file(const char* file)
{
  image_data = stbi_load(file, &width, &height, &num_comp, 4);
  if (NULL == image_data)
    printf("Texture loading failed: %s\n",file);
  printf("Texture loaded: %s\n", file);
}

void Texture::tex_parameter(int param_name, int param)
{
  glBindTexture(GL_TEXTURE_2D, texture_id);
  glTexParameteri(GL_TEXTURE_2D, param_name, param);
}

void Texture::bind(unsigned int unit)
{
  glActiveTexture(GL_TEXTURE0 + unit);
  glBindTexture(GL_TEXTURE_2D, texture_id);
}