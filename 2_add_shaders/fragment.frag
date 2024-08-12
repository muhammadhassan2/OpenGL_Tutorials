#version 330 core
out vec4 FragColor;
in vec2 tc;
uniform sampler2D ourTexture;

void main()
{
   vec4 tex = texture2D(ourTexture,1.0 -tc);
   FragColor = vec4(tex.r,tex.g,tex.b,tex.z);
}