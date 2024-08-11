#include"window.h"


window::window(GLuint width , GLuint height) {

	this->Initiate();

	mWindow = glfwCreateWindow(width, height, "myApp", NULL, NULL);

	if (!mWindow) {
		std::cout << "Failed to Create GLFW Window\n";
		glfwTerminate();
	}

	glfwMakeContextCurrent(mWindow);

	gladLoadGL();

	glViewport(0, 0, width,height);

}

void window::Initiate() {
	glfwInit();
	if (!glfwInit()) {
		std::cout << "Failed to Initiate GLFW\n";
		glfwTerminate();
	}
	this->setContext();
}
void window::setContext() {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}
bool window::shouldClose() const {
	return glfwWindowShouldClose(this->mWindow);
}

void window::update() {
	glfwSwapBuffers(mWindow);
	glfwPollEvents();
}
window::~window() {
	glfwDestroyWindow(mWindow);
	glfwTerminate();
}