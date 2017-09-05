#include "shader.h"

#include <string>
#include <iostream>

void Shader::load_from_file(const std::string &file) 
{
  const auto type = file.substr(file.length()-3, file.length());

  if (type == ".vs") {
    vs  = createShader(file.c_str(), GL_VERTEX_SHADER);
    glAttachShader(program, vs);
  }
  else if (type == ".fs") {
    fs  = createShader(file.c_str(), GL_FRAGMENT_SHADER);
    glAttachShader(program, fs);
  }
  else if (type == ".gs") {
    gs  = createShader(file.c_str(), GL_GEOMETRY_SHADER);
    glAttachShader(program, gs);
  }
  else {
    std::cerr << "[revork warning] not a valid shader type. file: '" << file << "'\n";
  }
}

void Shader::bind_attrib(int index, const char* name)
{
  glBindAttribLocation(program, index, name);
}

void Shader::init()
{
  program = glCreateProgram();
}

void Shader::link()
{
  glLinkProgram(program);
  glValidateProgram(program);
  validateShaderProgram("shader", program);
  glDetachShader(program, vs);
  glDetachShader(program, fs);
  glDetachShader(program, gs);
}

void Shader::bind()
{
  glUseProgram(program);
}

void Shader::setUniform(const char *name, float x,float y,float z)
{
  glUniform3f(glGetUniformLocation(program, name), x, y, z);      
}
void Shader::setUniform(const char *name, const glm::vec3& v)
{
  glUniform3f(glGetUniformLocation(program, name), v.x, v.y, v.z);      
}
void Shader::setUniform(const char *name, const glm::vec4& v)
{
  glUniform4f(glGetUniformLocation(program, name), v.x, v.y, v.z, v.w);    
}
void Shader::setUniform(const char *name, const glm::mat4& m)
{
  glUniformMatrix4fv(glGetUniformLocation(program, name), 1, GL_FALSE, &m[0][0]);  
}
void Shader::setUniform(const char *name, const glm::mat3& m)
{
  glUniformMatrix3fv(glGetUniformLocation(program, name), 1, GL_FALSE, &m[0][0]);    
}
void Shader::setUniform(const char *name, float val )
{
  glUniform1f(glGetUniformLocation(program, name), val);    
}
void Shader::setUniform(const char *name, int val )
{
  glUniform1i(glGetUniformLocation(program, name), val);    
}
void Shader::setUniform(const char *name, bool val )
{
  glUniform1i(glGetUniformLocation(program, name), val);      
}