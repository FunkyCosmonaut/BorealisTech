#pragma once
#include <glad/glad.h>
#include "borealistech/core/camera.hpp"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

class Renderer {
public:
    Renderer(Camera& camera);
    ~Renderer();
    bool Initialize();
    void RenderScene();
    GLFWwindow* GetWindow() const;

private:
    Camera& camera_;
    GLFWwindow* window_;
    GLuint shaderProgram_;
    GLuint VAO_;
    GLuint VBO_;

     // Add model, view, and projection matrices as member variables
    glm::mat4 model_;
    glm::mat4 view_;
    glm::mat4 projection_;

    //object stuff
    std::vector<GLfloat> vertices;
    std::vector<GLfloat> texCoords;
    std::vector<GLfloat> normals;
};