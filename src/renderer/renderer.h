#pragma once 

#include "skybox.h"
#include "../entity/entity.h"

#include <string>
#include <vector>
#include <glm/glm.hpp>

class Renderer {
private:
  glm::vec2 viewport;
  Skybox skybox;
  
public:
  std::vector<Entity*> entities;  
  void init();
  void shutdown();
  void render();

  void set_skybox(const std::vector<std::string> &faces);
};