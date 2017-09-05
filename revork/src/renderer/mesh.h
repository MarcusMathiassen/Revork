#pragma once

#define GLEW_STATIC
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <cstdint>
#include <iostream>
#include <vector>
#include "../utility.h"

struct Mesh
{
  enum {POSITION, NORMAL, UV, INDEX, NUM_BUFFERS};
  unsigned int VAO{0}, VBO[NUM_BUFFERS]{0};
  short drawCount{0};
  float drawType{GL_TRIANGLES};

  std::vector<glm::vec3> positions;
  std::vector<glm::vec3> normals;
  std::vector<glm::vec2> uvs;
  std::vector<short>  indices;

  void draw()
  {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glDisable(GL_BLEND);
    glBindVertexArray(VAO);
    //glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, drawCount);
    glEnable(GL_BLEND);
  }


  Mesh() = default;
  Mesh(const char* file)
  {
    std::vector<glm::vec3> positions;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> uvs;
    std::vector<short>  indices;
    loadOBJ(file, &positions, &normals, &uvs, &indices);
    printf("Mesh loaded: %s\n", file);
    
    drawCount = (short)positions.size();

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    if (!positions.empty())
    {
      glGenBuffers(1, &VBO[POSITION]);
      glBindBuffer(GL_ARRAY_BUFFER, VBO[POSITION]);
      glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);
      glEnableVertexAttribArray(0);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    }

    if (!uvs.empty())
    {
      glGenBuffers(1, &VBO[UV]);
      glBindBuffer(GL_ARRAY_BUFFER, VBO[UV]);
      glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(uvs[0]), &uvs[0], GL_STATIC_DRAW);
      glEnableVertexAttribArray(1);
      glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
    }

    if (!normals.empty())
    {
      glGenBuffers(1, &VBO[NORMAL]);
      glBindBuffer(GL_ARRAY_BUFFER, VBO[NORMAL]);
      glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(normals[0]), &normals[0], GL_STATIC_DRAW);
      glEnableVertexAttribArray(2);
      glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
    }

    if (!indices.empty())
    {
      glGenBuffers(1, &VBO[INDEX]);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO[INDEX]);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);
    }
  }

  ~Mesh()
  {
    //glDeleteBuffers(NUM_BUFFERS, VBO);
    //glDeleteVertexArrays(1, &VAO);
  }
};
