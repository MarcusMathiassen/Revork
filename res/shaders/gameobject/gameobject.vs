#version 330

in vec3 position;
in vec2 text_coord;
in vec3 normal;

uniform mat4 MVP;

out Vertex
{
  vec2 text_coord;
  vec3 normal;
} vertex;

void main()
{
  gl_Position = MVP * vec4(position, 1.0);

  vertex.text_coord = text_coord;
  vertex.normal = (MVP * vec4(normal, 0.0)).xyz;
}
