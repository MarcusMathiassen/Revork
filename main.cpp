#define STB_IMAGE_IMPLEMENTATION
#include "revork/revork.h"

unsigned int font;

int main() {
  Revork revork;
  revork.init();

//
  GameObject sphere;
  sphere.shader.init();
  sphere.shader.load_from_file("../revork/res/shaders/gameobject/gameobject.vs");
  sphere.shader.load_from_file("../revork/res/shaders/gameobject/gameobject.fs");
  sphere.shader.bind_attrib(0, "position");
  sphere.shader.bind_attrib(1, "text_coord");
  sphere.shader.bind_attrib(2, "normal");
  sphere.shader.link();

  sphere.texture.init();
  sphere.texture.load_file("../revork/res/textures/container.jpg");
  sphere.texture.tex_parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  sphere.texture.tex_parameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
  sphere.texture.tex_parameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  sphere.texture.tex_parameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  sphere.texture.tex_parameter(GL_TEXTURE_MAX_LEVEL, 3);
  sphere.texture.end();

  sphere.mesh = Mesh("../revork/res/meshes/sphereUV.obj");

//
  GameObject handgun;
  handgun.shader.init();
  handgun.shader.load_from_file("../revork/res/shaders/gameobject/gameobject.vs");
  handgun.shader.load_from_file("../revork/res/shaders/gameobject/gameobject.fs");
  handgun.shader.bind_attrib(0, "position");
  handgun.shader.bind_attrib(1, "text_coord");
  handgun.shader.bind_attrib(2, "normal");
  handgun.shader.link();

  handgun.texture.init();
  handgun.texture.load_file("../revork/res/textures/container.jpg");
  handgun.texture.tex_parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  handgun.texture.tex_parameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
  handgun.texture.tex_parameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  handgun.texture.tex_parameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  handgun.texture.tex_parameter(GL_TEXTURE_MAX_LEVEL, 3);
  handgun.texture.end();

  handgun.mesh = Mesh("../revork/res/meshes/handgunUV.obj");

//
  GameObject cube;
  cube.shader.init();
  cube.shader.load_from_file("../revork/res/shaders/gameobject/gameobject.vs");
  cube.shader.load_from_file("../revork/res/shaders/gameobject/gameobject.fs");
  cube.shader.bind_attrib(0, "position");
  cube.shader.bind_attrib(1, "text_coord");
  cube.shader.bind_attrib(2, "normal");
  cube.shader.link();

  cube.texture.init();
  cube.texture.load_file("../revork/res/textures/container.jpg");
  cube.texture.tex_parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  cube.texture.tex_parameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
  cube.texture.tex_parameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  cube.texture.tex_parameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  cube.texture.tex_parameter(GL_TEXTURE_MAX_LEVEL, 3);
  cube.texture.end();

  cube.mesh = Mesh("../revork/res/meshes/cubeUV.obj");

  GameObject monkey;
  monkey.shader.init();
  monkey.shader.load_from_file("../revork/res/shaders/gameobject/gameobject.vs");
  monkey.shader.load_from_file("../revork/res/shaders/gameobject/gameobject.fs");
  monkey.shader.bind_attrib(0, "position");
  monkey.shader.bind_attrib(1, "text_coord");
  monkey.shader.bind_attrib(2, "normal");
  monkey.shader.link();

  monkey.texture.init();
  monkey.texture.load_file("../revork/res/textures/container.jpg");
  monkey.texture.tex_parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  monkey.texture.tex_parameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
  monkey.texture.tex_parameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  monkey.texture.tex_parameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  monkey.texture.tex_parameter(GL_TEXTURE_MAX_LEVEL, 3);
  monkey.texture.end();

  monkey.mesh = Mesh("../revork/res/meshes/monkeyUV.obj");

//

  //
  GameObject ico_sphere;
  ico_sphere.shader.init();
  ico_sphere.shader.load_from_file("../revork/res/shaders/gameobject/gameobject.vs");
  ico_sphere.shader.load_from_file("../revork/res/shaders/gameobject/gameobject.fs");
  ico_sphere.shader.bind_attrib(0, "position");
  ico_sphere.shader.bind_attrib(1, "text_coord");
  ico_sphere.shader.bind_attrib(2, "normal");
  ico_sphere.shader.link();

  ico_sphere.texture.init();
  ico_sphere.texture.load_file("../revork/res/textures/container.jpg");
  ico_sphere.texture.tex_parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  ico_sphere.texture.tex_parameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
  ico_sphere.texture.tex_parameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  ico_sphere.texture.tex_parameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  ico_sphere.texture.tex_parameter(GL_TEXTURE_MAX_LEVEL, 3);
  ico_sphere.texture.end();

  ico_sphere.mesh = Mesh("../revork/res/meshes/icosphereUV.obj");

//
  cube.transform.pos.x += 5.0f;
  handgun.transform.pos.x += 10.0f;
  ico_sphere.transform.pos.y += 5.0f;
  monkey.transform.pos.x += 5.0f;
  monkey.transform.pos.y += 5.0f;
  revork.add_gameobject(&sphere);
  revork.add_gameobject(&ico_sphere);
  revork.add_gameobject(&handgun);
  revork.add_gameobject(&monkey);
  revork.add_gameobject(&cube);

  const std::vector<std::string> faces
  {
      "../revork/res/skybox/default/right.jpg",
      "../revork/res/skybox/default/left.jpg",
      "../revork/res/skybox/default/top.jpg",
      "../revork/res/skybox/default/bottom.jpg",
      "../revork/res/skybox/default/back.jpg",
      "../revork/res/skybox/default/front.jpg"
  };
  revork.renderer.set_skybox(faces);

  revork.run();
  revork.shutdown();
}