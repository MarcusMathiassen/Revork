#pragma once

#include "entity.h"
#include "../camera.h"
#include "../renderer/shader.h"
#include "../renderer/texture.h"
#include "../renderer/mesh.h"
#include "../transform.h"

#include <glm/glm.hpp>
#include <iostream>

struct GameObject : public Entity
{
  Shader      shader;
  Texture     texture;
  Mesh        mesh;
  Transform   transform;

  void update() override
  {
    transform.rot.y = sin(static_cast<float>(glfwGetTime() * 0.5f));
  }

  void draw() override
  {
    shader.bind();
    texture.bind(0);

    glDisable(GL_BLEND);

    const auto m = transform.get_model();
    const auto v = camera.get_view_matrix();
    const auto p = camera.get_perspective_projection();
    const auto mvp = p * v * m;
    shader.setUniform("MVP", mvp);

    mesh.draw();
  }
};