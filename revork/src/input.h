#pragma once

#include <GLFW/glfw3.h>

#include "camera.h"
#include "config.h"

#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"

static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
static void cursor_enter_callback(GLFWwindow *window, int entered);
static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
static void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

static void init_input_callbacks(GLFWwindow *window) {

  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);  
  glfwSetCursorPosCallback(window, cursor_position_callback);
  glfwSetCursorEnterCallback(window, cursor_enter_callback);
  glfwSetMouseButtonCallback(window, mouse_button_callback);
  glfwSetScrollCallback(window, scroll_callback);
  glfwSetKeyCallback(window, key_callback);
}
static void process_inputs(GLFWwindow *window)
{
  float deltaTime = 0.0166f;

  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
      camera.process_keyboard(FORWARD, deltaTime);
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
      camera.process_keyboard(BACKWARD, deltaTime);
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
      camera.process_keyboard(LEFT, deltaTime);
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
      camera.process_keyboard(RIGHT, deltaTime);

  if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
    camera.process_keyboard(UP, deltaTime);

  if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
    camera.process_keyboard(DOWN, deltaTime);
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_I && action == GLFW_PRESS) 
    {
        show_menu ^= 1;  
        
        if (show_menu)
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        else
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); 
    }
    
    // IMGUI stuff
    ImGuiIO& io = ImGui::GetIO();
    if (action == GLFW_PRESS)
        io.KeysDown[key] = true;
    if (action == GLFW_RELEASE)
        io.KeysDown[key] = false;

    (void)mods; // Modifiers are not reliable across systems
    io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
    io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
    io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
    io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
}
bool first_mouse = true;
float last_x = (float)512 / 2.0;
float last_y = (float)512 / 2.0;
static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos) 
{
    
    if (first_mouse)
    {
        last_x = xpos;
        last_y = ypos;
        first_mouse = false;
    }

    float xoffset = xpos - last_x;
    float yoffset = last_y - ypos; // reversed since y-coordinates go from bottom to top

    last_x = xpos;
    last_y = ypos;

    if (show_menu) return;

    camera.process_mouse_movement(xoffset, yoffset);
}
static void cursor_enter_callback(GLFWwindow *window, int entered) {}
static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
}
static void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
  camera.process_mouse_scroll(yoffset * 0.01f);
  ImGui::GetIO().MouseWheel = yoffset;
}
