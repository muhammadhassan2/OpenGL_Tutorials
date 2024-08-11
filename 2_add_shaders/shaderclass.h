#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<istream>
#include"Helper.h"
#include<./glad/glad.h>
#include<./GLFW/glfw3.h>

std::string get_file_contents(const char* filename);

class Shader {

private:


public:

	Shader(const char *vertexShade , const char *fragmentShader);
	void createProgram(const GLuint vertex ,const GLuint fragment);
	void Activate();
	void Delete();
	void compileErrors(GLuint shaderId , shaderType type);
	void setFloat(const std::string &uniform_name ,float value);
	void setInt(const std::string &uniform_name ,int value);
	std::string vertexCode, fragmentCode;

	GLuint programID;

};
