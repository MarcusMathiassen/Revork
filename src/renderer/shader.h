#pragma once

#include "utility.h"

#define GLEW_STATIC
#include <GL/glew.h>

#include <cstdio>
#include <vector>

struct Shader
{
  unsigned int program, vs, fs, gs;
  
  void bind();
  void init();  
  void link();
  void bind_attrib(int index, const char* name);
  void load_from_file(const std::string &file);

  void setUniform(const char *name, float x,float y,float z);
  void setUniform(const char *name, const glm::vec3 & v);
  void setUniform(const char *name, const glm::vec4 & v);
  void setUniform(const char *name, const glm::mat4 & m);
  void setUniform(const char *name, const glm::mat3 & m);
  void setUniform(const char *name, float val );
  void setUniform(const char *name, int val );
  void setUniform(const char *name, bool val );
};

static void validateShader(const char *file, const char *type, unsigned int shader)
{
  char  infoLog[512] = {0};
  int     success;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(shader, sizeof(infoLog), NULL, infoLog);
    printf("\nERROR::FILE %s\n", file);
    printf("ERROR::SHADER::%s::COMPILATION::FAILED\n\n%s", type, infoLog);
  }
}

static void validateShaderProgram(const char* name, unsigned int shaderProgram)
{
  char  infoLog[512] = {0};
  int   success;
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetProgramInfoLog(shaderProgram, sizeof(infoLog), NULL, infoLog);
    printf("\nERROR::SHADER::PROGRAM::%s::LINKING::FAILED\n\n%s",name, infoLog);
  }
}

static unsigned int createShader(const char *file, const GLenum type)
{
  char *source = NULL;
  readFile(file, &source);

  unsigned int shader = glCreateShader(type);
  if (NULL != source)
  {
    glShaderSource(shader, 1, &source, NULL);
    free(source);
  }

  glCompileShader(shader);

  switch (type)
  {
    case GL_VERTEX_SHADER:    validateShader(file, "VERTEX",    shader); break;
    case GL_FRAGMENT_SHADER:  validateShader(file, "FRAGMENT",  shader); break;
    case GL_GEOMETRY_SHADER:  validateShader(file, "GEOMETRY",  shader); break;
  }
  printf("Shader loaded: %s\n", file);
  return shader;
}
