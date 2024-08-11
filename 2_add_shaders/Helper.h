#pragma once

#include<iostream>
#include"./glad/glad.h"
#include"./GLFW/glfw3.h"
#include<string>
#include<sstream>
#include<fstream>
#include<istream>
using namespace std;

const GLuint WindowWidth = 720.0, WindowHeight = 720.0;

enum class shaderType{VERTEX , FRAGMENT ,PROGRAM};

inline std::string get_file_contents(const char* filename);


