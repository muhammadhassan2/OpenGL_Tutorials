#include"window.h"


window::window(GLuint width, GLuint height) :mWidth{ width }, mHeight{height} {

	this->Initiate();

	mWindow = glfwCreateWindow(mWidth, mHeight, "myApp", NULL, NULL);

	if (!mWindow) {
		std::cout << "Failed to Create GLFW Window\n";
		glfwTerminate();
	}

	glfwMakeContextCurrent(mWindow);

	glfwSetFramebufferSizeCallback(mWindow, [](GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
		}
	);

	glfwSetKeyCallback(mWindow,
		[](GLFWwindow* m_window, int key, int scancode, int action, int mods) {
			auto* win = static_cast<window*>(glfwGetWindowUserPointer(m_window));
			if (win) {
				win->KeyCallback(key, action);
			}
		}
	);

	gladLoadGL();

	glViewport(0, 0, width,height);

}
void window::KeyCallback(int key, int action) {
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_W) {
			//this->setF
		}

	}
	else if (action == GLFW_RELEASE) {
		std::cout << "Key " << key << " is released" << std::endl;
	}
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

void window::closeWindow() {
	glfwSetWindowShouldClose(mWindow,GLFW_TRUE);
}

bool window::getKey(int key) {
	if (glfwGetKey(mWindow, key) == GLFW_PRESS) {
		return true;
	}
	return false;
}
window::~window() {
	glfwDestroyWindow(mWindow);
	glfwTerminate();
}