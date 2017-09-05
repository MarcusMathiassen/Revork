#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum Camera_Movement {
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT,
  DOWN,
  UP
};

// Default camera values
const float YAW        = -90.0f;
const float PITCH      =  0.0f;
const float SPEED      =  4.5f;
const float SENSITIVTY =  0.1f;
const float ZOOM       =  45.0f;


struct Camera
{
  // Camera Attributes
  glm::vec3 position{0.0f, 0.0f, 0.0f};
  glm::vec3 front{0.0f, 0.0f, -1.0f};
  glm::vec3 up{0, 1, 0};
  glm::vec3 right;
  glm::vec3 world_up{0, 1, 0};
  // Eular Angles
  float yaw{YAW};
  float pitch{PITCH};
  // Camera options
  float movement_speed{SPEED};
  float mouse_sensitivity{SENSITIVTY};
  float zoom{ZOOM};

  float fov{45.0f};
  float aspectRatio{1280/720};
  float zNear{0.1f};
  float zFar{1000.0f};
  float moveSpeed{0.02f};

  glm::mat4 view_matrix;
  glm::mat4 *active_projection;
  glm::mat4 perspective_projection;
  glm::mat4 ortho_projection;

  Camera() { update_camera_vectors(); }

  void update();
  void update_projection(float width, float height);

  glm::mat4 get_view_matrix() const;
  glm::mat4 get_view_projection() const;
  glm::mat4 get_perspective_projection() const;
  glm::mat4 get_ortho_projection() const;

  void process_mouse_scroll(float yoffset);  
  void process_mouse_movement(float xoffset, float yoffset, bool constrain_pitch = true);  
  void process_keyboard(Camera_Movement direction, float deltaTime);
  void update_camera_vectors();
  void use_projection_ortho();
  void use_projection_perspective();
};

extern Camera camera;