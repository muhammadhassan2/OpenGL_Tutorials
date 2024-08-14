#version 330 core
out vec4 FragColor;
in vec2 tc;
uniform sampler2D tex0;
uniform sampler2D tex1;
uniform float time;
void main()
{
   vec4 tex_1 = texture2D(tex0, tc);
    vec4 tex_2 = texture2D(tex1, tc);
   FragColor = mix(tex_1,tex_2,sin(time));       // Simple mix of two textures
}
