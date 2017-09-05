#pragma once
#include "../../dep/universal/stb_image.h"

struct Texture
{
  unsigned int texture_id;
  int width, height, num_comp;
  unsigned char *image_data;

  void init();
  void end();
  void load_file(const char* file);
  void tex_parameter(int param_name, int param);  
  void bind(unsigned int unit);
};