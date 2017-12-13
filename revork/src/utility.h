#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include <cmath>
#include <sstream>
#include <vector>

#include <glm/glm.hpp>

#ifdef _WIN32
#include <windows.h>
#elif __APPLE__
#include <ctime>
#include <unistd.h>
#endif

static void loadOBJ(const char *file, std::vector<glm::vec3> *vertices,
                    std::vector<glm::vec3> *normals,
                    std::vector<glm::vec2> *uvs, std::vector<short> *indices);
static void limit_FPS(unsigned int desired_framerate, double time_start_frame) {
  const double frametime = (1000.0 / desired_framerate);
  double time_spent_frame = (glfwGetTime() - time_start_frame) * 1000.0;
  const double time_to_sleep = (frametime - time_spent_frame) * 0.7;

  if (time_to_sleep > 0.0) {
    if (time_to_sleep >
        2.0) // because of the inconsistent wakeup times from sleep
    {
#ifdef _WIN32
      Sleep((DWORD)time_to_sleep);
#elif __APPLE__
      const timespec time_in_nanoseconds_to_sleep{0,
                                                  (long)(time_to_sleep * 1e6)};
      nanosleep(&time_in_nanoseconds_to_sleep, NULL);
#endif
    }
    while (time_spent_frame < frametime) {
      time_spent_frame = (glfwGetTime() - time_start_frame) * 1000.0;
    }
  }
}
static void readFile(const char *file, char **buffer);
#ifdef _WIN32
static glm::vec3 getHSV(short h, float s, float v);
#else
static constexpr glm::vec3 getHSV(short h, float s, float v);
#endif

static void limitFPS(unsigned int framesPerSecond, double timeStartFrame) {
  const double frametime = (double)(1000.0 / framesPerSecond);
  double timeSpentFrame{(glfwGetTime() - timeStartFrame) * 1000.0};
  const double sleepTime{(frametime - timeSpentFrame) * 0.8};
  if (sleepTime > 0.0) {
#ifdef _WIN32
    Sleep((DWORD)sleepTime);
#elif __APPLE__ // @TODO: fix unix sleep. Very unstable compared to WIN32
    nanosleep(
        (const struct timespec[]){{0, static_cast<long>(sleepTime * 1e6)}},
        NULL);
#endif
    while (timeSpentFrame < frametime) {
      timeSpentFrame = (glfwGetTime() - timeStartFrame) * 1000.0;
    }
  }
}

static void readFile(const char *file, char **buffer) {
  std::string buff, line;
  std::ifstream fileIn(file);
  while (std::getline(fileIn, line))
    buff += line + '\n';
  *buffer = (char *)malloc((buff.length() + 1) * sizeof(char));
  strcpy(*buffer, buff.c_str());
}

#ifdef _WIN32
static glm::vec3 getHSV(short h, float s, float v)
#else
static constexpr glm::vec3 getHSV(short h, float s, float v)
#endif
{
  h = (h >= 360) ? 0 : h;
  const float hue{(float)h * 0.016666f};

  const char i{(char)hue};
  const float f{hue - i};
  const float p{v * (1.0f - s)};
  const float q{v * (1.0f - s * f)};
  const float t{v * (1.0f - s * (1.0f - f))};

  float r{0.0f}, g{0.0f}, b{0.0f};

  switch (i) {
  case 0:
    r = v;
    g = t;
    b = p;
    break;
  case 1:
    r = q;
    g = v;
    b = p;
    break;
  case 2:
    r = p;
    g = v;
    b = t;
    break;
  case 3:
    r = p;
    g = q;
    b = v;
    break;
  case 4:
    r = t;
    g = p;
    b = v;
    break;
  case 5:
  default:
    r = v;
    g = p;
    b = q;
    break;
  }
  return glm::vec3(r, g, b);
}

static void loadOBJ(const char *file, std::vector<glm::vec3> *vertices,
                    std::vector<glm::vec3> *normals,
                    std::vector<glm::vec2> *uvs, std::vector<short> *indices) {
  char *buffer;
  readFile(file, &buffer);

  std::stringstream ss;
  ss << buffer;

  if (NULL != buffer)
    free(buffer);

  std::vector<glm::vec3> temp_vertices;
  std::vector<glm::vec3> temp_normals;
  std::vector<glm::vec2> temp_uvs;
  std::vector<short> vert_indices, uv_indices, norm_indices;

  bool hasUV{false}, hasNormal{false};

  std::string line;
  while (std::getline(ss, line)) {
    if (line[0] == '#')
      continue;

    if (line[0] == 'v') {
      switch (line[1]) {
      case ' ': {
        glm::vec3 v;
        sscanf(line.c_str() + 1, "%f %f %f", &v.x, &v.y, &v.z);
        temp_vertices.emplace_back(v);
      } break;

      case 'n': {
        hasNormal = true;
        glm::vec3 n;
        sscanf(line.c_str() + 2, "%f %f %f", &n.x, &n.y, &n.z);
        temp_normals.emplace_back(n);
      } break;

      case 't': {
        hasUV = true;
        glm::vec2 t;
        sscanf(line.c_str() + 2, "%f %f", &t.x, &t.y);
        temp_uvs.emplace_back(t);
      } break;
      }
    } else if (line[0] == 'f') {
      short v_i[3]{0}, vn_i[3]{0}, vt_i[3]{0};

      char numOfSlashes{0};
      for (const auto &chr : line)
        if (chr == '/')
          ++numOfSlashes;
      switch (numOfSlashes) {
      case 0: {
        sscanf(line.c_str() + 2, "%hd %hd %hd", &v_i[0], &v_i[1], &v_i[2]);
      } break;

      case 3: {
        sscanf(line.c_str() + 2, "%hd/%hd %hd/%hd %hd/%hd", &v_i[0], &vt_i[0],
               &v_i[1], &vt_i[1], &v_i[2], &vt_i[2]);
      } break;

      case 6: {
        if (hasNormal && hasUV) {
          sscanf(line.c_str() + 2, "%hd/%hd/%hd %hd/%hd/%hd %hd/%hd/%hd",
                 &v_i[0], &vt_i[0], &vn_i[0], &v_i[1], &vt_i[1], &vn_i[1],
                 &v_i[2], &vt_i[2], &vn_i[2]);
        } else {
          sscanf(line.c_str() + 2, "%hd//%hd %hd//%hd %hd//%hd", &v_i[0],
                 &vn_i[0], &v_i[1], &vn_i[1], &v_i[2], &vn_i[2]);
        }
      } break;

      case 9: {
        sscanf(line.c_str() + 2, "%hd//%hd//%hd %hd//%hd//%hd %hd//%hd//%hd",
               &v_i[0], &vt_i[0], &vn_i[0], &v_i[1], &vt_i[1], &vn_i[1],
               &v_i[2], &vt_i[2], &vn_i[2]);
      } break;
      }

      vert_indices.emplace_back(v_i[0]);
      vert_indices.emplace_back(v_i[1]);
      vert_indices.emplace_back(v_i[2]);
      if (hasUV) {
        uv_indices.emplace_back(vt_i[0]);
        uv_indices.emplace_back(vt_i[1]);
        uv_indices.emplace_back(vt_i[2]);
      }
      if (hasNormal) {
        norm_indices.emplace_back(vn_i[0]);
        norm_indices.emplace_back(vn_i[1]);
        norm_indices.emplace_back(vn_i[2]);
      }
    }
  }

  vertices->reserve(vert_indices.size());
  for (const auto &vert_i : vert_indices)
    vertices->emplace_back(temp_vertices[vert_i - 1]);

  if (hasNormal) {
    normals->reserve(norm_indices.size());
    for (const auto &norm_i : norm_indices)
      normals->emplace_back(temp_normals[norm_i - 1]);
  }

  if (hasUV) {
    uvs->reserve(uv_indices.size());
    for (const auto &uv_i : uv_indices)
      uvs->emplace_back(temp_uvs[uv_i - 1]);
  }

  std::cout << "file: " << file << '\n';
  std::cout << "      positions: " << vertices->size() << '\n';
  std::cout << "      normals: " << normals->size() << '\n';
  std::cout << "      uvs: " << uvs->size() << '\n';
}
