#include<iostream>
#include"./glad/glad.h"
#include"./GLFW/glfw3.h"
#include "Helper.h"
#include"shaderclass.h"
#include "window.h"
#include"texture.h"
// GLM
#include <./glm/glm.hpp>
#include <./glm/gtc/matrix_transform.hpp>
#include <./glm/gtc/type_ptr.hpp>

//images
#include<stb/stb_image.h>
using namespace std;

GLfloat vertices[] = {
	// Pos                 // Color
	0.0f , .5f ,0.0f,      1.0f ,0.0f ,0.0f,
	-.5f ,-.5f ,0.0f,      0.0f ,1.0f ,0.0f,
	.5f , -.5f , 0.0f,      0.0f ,0.0f ,1.0f
};

GLfloat texVertices[] = {
	// Pos                 // Color                 // tex
	 -0.5f , -.5f ,0.0f,      1.0f ,0.0f ,0.0f,      0.0f, 0.0f,
	.5f ,-.5f ,0.0f,      0.0f ,1.0f ,0.0f,      1.0f, 0.0f,
	.5f , .5f , 0.0f,      0.0f ,0.0f ,1.0f,     1.0f, 1.0f,

    0.5f , .5f ,0.0f,      1.0f ,0.0f ,0.0f,      1.0f, 1.0f,
   -.5f ,.5f ,0.0f,      0.0f ,1.0f ,0.0f,       0.0f, 1.0f,
   -.5f , -.5f , 0.0f,      0.0f ,0.0f ,1.0f,      0.0f, 0.0f,

};
int main() {

	window mWindow(WindowWidth,WindowHeight);
	GLuint VAO, VBO;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(texVertices), &texVertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8 * sizeof(float),(void*) (3*sizeof(float)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float),(void*)(6*sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	Shader Shaderclass("vertex.vert","fragment.frag");
	GLuint currentPressedKey;
	
	Texture Cat("G:\\pop_cat.png",GL_TEXTURE_2D,GL_TEXTURE0);
	Texture myImage("G:\\qa.jpg", GL_TEXTURE_2D, GL_TEXTURE1);
	Cat.texUnit(Shaderclass, "tex0", 0);
	myImage.texUnit(Shaderclass, "tex1", 1);
	//Shaderclass.setInt("tex0", 0);
	//Shaderclass.setInt("tex1", 1);
	while (!mWindow.shouldClose()) {
		float time = glfwGetTime();
		Shaderclass.setFloat("time",sin(time));

		glClearColor(.1f, .2f, .3f, 1.0f);
		if (mWindow.getKey(GLFW_KEY_W) == true) {
			std::cout << "The pressed key is W\n";
			Shaderclass.setFloat("move_up", .1);
		}

	    Cat.bind();
		myImage.bind();

		glClear(GL_COLOR_BUFFER_BIT);
		Shaderclass.Activate();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		mWindow.update();
	}


}