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
	GLuint mWidth, mHeight;
	bool shouldClose() const ;
	void update();
	void KeyCallback(int key, int action);
	void closeWindow();
	bool getKey(int key);
	GLFWwindow* mWindow;
	void Initiate();

};