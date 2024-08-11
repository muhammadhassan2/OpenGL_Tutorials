#pragma once
#include"./glad/glad.h"
#include"./GLFW/glfw3.h"
#include"Helper.h"
#include<iostream>

class window {

private:
	void setContext();
public:
	window(GLuint width, GLuint height);
	~window();
	bool shouldClose() const ;
	void update();
	GLFWwindow* mWindow;
	void Initiate();

};