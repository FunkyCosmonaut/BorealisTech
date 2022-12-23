#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

int init_glfw();
int init_window();
GLuint genbuffer();
void render(GLuint vbuffer);
