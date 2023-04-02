#pragma once
#include <GLFW/glfw3.h>
#include "impetus/core/camera.hpp"

class Camera;

class Renderer {
public:
    Renderer();
    ~Renderer();

    void Initialize(int width, int height);
    void RenderScene();

private:

    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
    Camera* camera;
    // Add members for shaders, VAOs, VBOs, etc.
    GLuint shaderProgram;

    // Vertex Array Object
    GLuint VAO;

    // Vertex Buffer Object
    GLuint VBO;

    // Functions to create and compile shaders
    GLuint CreateShader(GLenum shaderType, const char* shaderSource);
    GLuint CreateShaderProgram(GLuint vertexShader, GLuint fragmentShader);

};