#pragma once
#include<iostream>
#include<string>
#include"./glad/glad.h"
#include"./GLFW/glfw3.h"
#include"shaderclass.h"
#include<stb/stb_image.h>
class Texture{
private:


public:
	Texture(const char * texturePath, GLenum texType, GLenum slot);
	GLenum getTextureFormat();
	void texUnit(Shader& shader, const char* uniform, GLuint unit);
	void bind(GLuint unit);
	unsigned char* data;
	GLuint textureID;
	int texWidth, texHeight, texChannels;
	int texFormat;
	GLenum format;


};
