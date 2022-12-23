#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

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
	return 0;
}

int main(){

	init();
	windowCreate();



	return 0;


}

