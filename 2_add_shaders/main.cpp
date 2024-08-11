#include<iostream>
#include"./glad/glad.h"
#include"./GLFW/glfw3.h"
#include "Helper.h"
#include"shaderclass.h"
#include "window.h"
// GLM
#include <./glm/glm.hpp>
#include <./glm/gtc/matrix_transform.hpp>
#include <./glm/gtc/type_ptr.hpp>

using namespace std;

GLfloat vertices[] = {
	0.0f , .5f ,0.0f,
	-.5f ,-.5f ,0.0f,
	.5f , -.5f , 0.0f
};

int main() {

	window mWindow(WindowWidth,WindowHeight);
	glm::vec3(1.0);
	GLuint VAO, VBO;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glEnableVertexAttribArray(0);

	Shader Shaderclass("vertex.vert","fragment.frag");
	GLuint currentPressedKey;


	while (!mWindow.shouldClose()) {
		float time = glfwGetTime();
		//Shaderclass.setFloat("time",sin(time));

		glClearColor(.1f, .2f, .3f, 1.0f);
		if (mWindow.getKey(GLFW_KEY_W) == true) {
			std::cout << "The pressed key is W\n";
			Shaderclass.setFloat("move_up", .1);
		}


		glClear(GL_COLOR_BUFFER_BIT);
		Shaderclass.Activate();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		mWindow.update();
	}


}