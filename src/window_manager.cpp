#include "./window_manager.h"

#include "./camera.h"

#include <iostream>
#include <string>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

static void window_iconify_callback(GLFWwindow* window, int iconified);
static void window_focus_callback(GLFWwindow* window, int focused);
static void drop_callback(GLFWwindow* window, int count, const char** paths);
static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void window_size_callback(GLFWwindow* window, int width, int height);

void WindowManager::init() {
  if (!glfwInit()) {
    std::cerr << "[revork error] GLFW init failed\n";
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#if __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  window = glfwCreateWindow(window_width, window_height, window_title.c_str(), nullptr, nullptr);
  glfwMakeContextCurrent(window);

  glfwSetWindowIconifyCallback(window, window_iconify_callback);
  glfwSetWindowFocusCallback(window, window_focus_callback);
  glfwSetWindowSizeCallback(window, window_size_callback);
  glfwSetDropCallback(window, drop_callback);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  glewExperimental = true;
  if (glewInit() != GLEW_OK) {
    std::cerr << "[revork error] GLEW init failed\n";
  }

  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0, 0, width, height);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void WindowManager::shutdown() {
  glfwTerminate();
}

static void window_size_callback(GLFWwindow* window, int xpos, int ypos) {
  std::cout << "[revork log] Window size: " << xpos << ":" << ypos << std::endl;
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  std::cout << "[revork log] Framebuffer size: " << width << ":" << height << std::endl;
  glViewport(0, 0, width, height);
  camera.update_projection(static_cast<float>(width), static_cast<float>(height));  
}

static void window_iconify_callback(GLFWwindow* window, int iconified) {
  if (iconified) {
    std::cout << "[revork log] The window was iconified" << std::endl;
  } else {
    std::cout << "[revork log] The window was restored" << std::endl;
  }
}

static void window_focus_callback(GLFWwindow* window, int focused) {
  if (focused) {
    std::cout << "[revork log] The window gained input focus" << '\n';
  } else {
    std::cout << "[revork log] The window lost input focus" << '\n';
  }
}

static void drop_callback(GLFWwindow* window, int count, const char** paths) { std::cout << "[revork log] Drag dropped: " << (*paths) << '\n'; }
