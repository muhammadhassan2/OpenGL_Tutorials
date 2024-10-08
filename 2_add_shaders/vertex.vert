#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;
out vec2 tc;
uniform float time;
void main()
{
   gl_Position = vec4(aPos.x -time, aPos.y, aPos.z, 1.0f);
   tc = texCoord;
}