#include "camera.h"

#include <glm/glm.hpp>
#include <cmath>
#include <iostream>
#include <glm/gtx/transform.hpp>

Camera camera;

glm::mat4 Camera::get_view_projection() const
{
  return *active_projection * view_matrix;
}

glm::mat4 Camera::get_view_matrix() const
{
  return view_matrix;
}

void Camera::process_mouse_movement(float xoffset, float yoffset, bool constrain_pitch)
{
  xoffset *= mouse_sensitivity;
  yoffset *= mouse_sensitivity;

  yaw   += xoffset;
  pitch += yoffset;

  // Make sure that when pitch is out of bounds, screen doesn't get flipped
  if (constrain_pitch)
  {
      if (pitch > 89.0f)
          pitch = 89.0f;
      if (pitch < -89.0f)
          pitch = -89.0f;
  }

  // Update front, right and Up Vectors using the updated Eular angles
  update_camera_vectors();
}

void Camera::update_camera_vectors()
{
        // Calculate the new front vector
        glm::vec3 n_front;
        n_front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        n_front.y = sin(glm::radians(pitch));
        n_front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        front = glm::normalize(n_front);
        // Also re-calculate the right and Up vector
        right = glm::normalize(glm::cross(front, world_up));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        up    = glm::normalize(glm::cross(right, front));
}

void Camera::process_mouse_scroll(float yoffset)
{
  if (zoom >= 44.0f && zoom <= 46.0f)
      zoom -= yoffset;
  if (zoom <= 44.0f)
      zoom = 44.0f;
  if (zoom >= 46.0f)
      zoom = 46.0f; 
}

void Camera::process_keyboard(Camera_Movement direction, float deltaTime)
{
  const float velocity = movement_speed * deltaTime;
  if (direction == FORWARD)
      position += front * velocity;
  if (direction == BACKWARD)
      position -= front * velocity;
  if (direction == LEFT)
      position -= right * velocity;
  if (direction == RIGHT)
      position += right * velocity;
  if (direction == DOWN)
      position -= up * velocity;
  if (direction == UP)
      position += up * velocity;
}

void Camera::update()
{
  view_matrix = glm::lookAt(position, position + front, up);
  perspective_projection = glm::perspective(zoom, aspectRatio, zNear, zFar);  
}

void Camera::update_projection(float width, float height)
{
  aspectRatio = width / height;
  perspective_projection = glm::perspective(zoom, aspectRatio, zNear, zFar);

  ortho_projection = glm::ortho(0.0f, width, 0.0f, height);
}

glm::mat4 Camera::get_perspective_projection() const
{
  return perspective_projection;
}

glm::mat4 Camera::get_ortho_projection() const
{
  return ortho_projection;
}

void Camera::use_projection_ortho() {
  active_projection = &ortho_projection;
}

void Camera::use_projection_perspective() {
  active_projection = &perspective_projection;
}