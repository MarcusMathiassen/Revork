#version 330 core
out vec4 frag_color;
uniform samplerCube skybox;

smooth in vec3 eyeDirection;

void main()
{    
    frag_color = texture(skybox, eyeDirection);
}