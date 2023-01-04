//#define GLFW_INCLUDE_NONE
#include <iostream>

#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>

//#include <GL/glew.h>
#include <glm/glm.hpp>


int init_glad();
int init_window();
GLuint genbuffer();
GLuint genarray();
GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
void render(GLuint vbuffer);
