
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
  void init();
  void shutdown();
};
