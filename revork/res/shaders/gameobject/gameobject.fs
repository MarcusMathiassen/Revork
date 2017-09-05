#version 330

out vec4 fragColor;

uniform sampler2D diffuse;

in Vertex
{
  vec2 text_coord;
  vec3 normal;
} frag;

void main()
{
  vec3 ambient = vec3(0.1, 0.1, 0.1);
  vec4 tex = texture(diffuse, frag.text_coord) * max(0.0, dot(-vec3(0,0,1), frag.normal));
  fragColor = tex + vec4(ambient,1);
}

