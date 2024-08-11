#include<iostream>
#include"./glad/glad.h"
#include"./GLFW/glfw3.h"
using namespace std;

const GLuint WIDTH = 720.0, HEIGHT = 720.0;

GLfloat vertices[] = {
	0.0f , .5f ,0.0f,
	-.5f ,.5f ,0.0f,
	.5f , -.3f , 0.0f
};

int main() {

	glfwInit();

	if (!glfwInit()) {
		std::cout << "ERROR-Can't Initiate glfw \n";
		glfwTerminate();
	}

	// seeting the glfw opengl context 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// create a glfw window to render on
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "my_app", NULL, NULL);


	if (!window) {
		std::cout << "ERROR-Can't Create a GLFW Window\n";
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();

	GLuint VAO, VBO;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glEnableVertexAttribArray(0);


	while (!glfwWindowShouldClose(window)) {

		glClearColor(.1f, .2f, .3f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);

		glfwPollEvents();

	}



	glfwTerminate();
}