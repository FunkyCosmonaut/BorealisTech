#pragma once

#include <vector>
#include <GLFW/glfw3.h>

class GameObject {
public:
    GameObject();
    ~GameObject();

    void Render();

private:
    GLuint VAO, VBO;
    std::vector<float> vertices;

    void SetupMesh();
};