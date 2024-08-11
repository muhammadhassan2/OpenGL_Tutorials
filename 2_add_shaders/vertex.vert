#version 330 core
layout (location = 0) in vec3 aPos;
uniform float move_up;
uniform float time;
void main()
{
   gl_Position = vec4(aPos.x - time, aPos.y, aPos.z, 1.0f);
}