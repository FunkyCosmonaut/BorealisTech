#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "main.h"

//using namespace glm;
using std::cout;
using std::cin;


int init(){
	glewExperimental = true;
	if(!glfwInit()){
		cout << stderr << "Failed\n";
		return -1;
	}
	else
		return 0;
}
int windowCreate(){
	
	glfwWindowHint(GLFW_SAMPLES, 4);

	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,0);
	GLFWwindow* window;
	window = glfwCreateWindow(1024, 768, "test", NULL, NULL);
	if(window == NULL){
		cout << stderr << "Failed to open GLFW window\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glewExperimental=true;
	if(glewInit() != GLEW_OK){
		cout << stderr << "Failed to initialize GLEW\n";
		return -1;
	}
	GLuint buffer = genbuffer();
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	do{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
		render(buffer);
	}
	while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
	return 0;
}

GLuint genbuffer(){

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
	};

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	
	return vertexbuffer;
}

void render(GLuint vbuffer){

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbuffer);
	glVertexAttribPointer(
	0,
	3,
	GL_FLOAT,
	GL_FALSE,
	0,
	(void*)0
	);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);

}


int main(){

	init();
	windowCreate();



	return 0;


}

