#pragma once

#include <string>
#include <GLFW/glfw3.h>

class Application {
public:
    Application(const std::string& windowTitle, int width, int height);
    ~Application();

    void Run();

private:
    void InitWindow();
    void InitOpenGL();

    std::string windowTitle;
    int width, height;
    
    GLFWwindow* window;
};