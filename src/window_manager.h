
#pragma once

#include "camera.h"

#include <iostream>
#include <string>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class WindowManager {

public:
  GLFWwindow *window;
  int window_width{1280}, window_height{720};
  std::string window_title{ "Revork" } ;

  void init();
  void shutdown();
};
