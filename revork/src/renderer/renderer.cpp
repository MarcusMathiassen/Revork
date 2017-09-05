#include "renderer.h"
#include "../camera.h"
#include "../imgui.h"

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void Renderer::render() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  camera.update();
  
  skybox.draw();


  glEnable(GL_CULL_FACE);
  for (auto &entity: entities) {
    entity->update();
    entity->draw();
  }
}


void Renderer::set_skybox(const std::vector<std::string> &faces) {
  skybox.faces = faces;
  skybox.init();
}

void Renderer::init() {
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.1,0.1,0.1,1.0);  
}

void Renderer::shutdown() {

}