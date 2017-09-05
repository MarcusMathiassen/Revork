#version 330 core
in vec3 position;

uniform mat4 projection;
uniform mat4 view;

smooth out vec3 eyeDirection;

void main()
{
    mat4 inverseProjection = inverse(projection);
    mat3 inverseModelview = transpose(mat3(view));
    vec3 unprojected = (inverseProjection * vec4(position,1)).xyz;
    eyeDirection = inverseModelview * unprojected;

    gl_Position = vec4(position,1).xyww;
}  