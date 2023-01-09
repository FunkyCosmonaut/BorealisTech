#include "render.hpp"

using namespace glm;
using std::cout;
using std::cin;

#define WIDTH 1024
#define HEIGHT 768

glm::mat4 genMVPmatrix(float width, float height){
// glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);

}

int init_glad(){

    if (!gladLoadGLES2Loader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    return 0;
}

int init_window(){

    if( !glfwInit() ){
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return -1;
    }
	
	glfwWindowHint(GLFW_SAMPLES, 4);

	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3.0);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,0);
	
    GLFWwindow* window;
	window = glfwCreateWindow(WIDTH, HEIGHT, "testies", NULL, NULL);
	if(window == NULL){
		cout << stderr << "Failed to open GLFW window\n";
		glfwTerminate();
		return -1;
    }

	glfwMakeContextCurrent(window);
   //maybe move this later
    init_glad();

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

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    GLuint programID = LoadShaders("graphics/vertex.shader", "graphics/fragment.shader");
    glViewport(0, 0, 800, 600);
    do{



        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(programID);
		render(vertexbuffer);
//

/*	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0,(void*)0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
*/
		glfwSwapBuffers(window);
		glfwPollEvents();


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

GLuint genarray(){


    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    return VertexArrayID;

}
//We might move this to an object
void render(GLuint vbuffer){

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0,(void*)0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);

}
