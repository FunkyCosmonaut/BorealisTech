#pragma once
#include <GLFW/glfw3.h>
#include "impetus/core/renderer.hpp"



#include "impetus/core/camera.hpp"

class Engine {
public:
    Engine(int width, int height);
    ~Engine();
    void run();

private:
    Renderer renderer;

    GLFWwindow* window;
    int width;
    int height;
   // Camera camera;
    float lastFrame = 0.0f;
    
    void initializeGLFW();
    void createWindow();
    void initializeGLAD();
    void configureOpenGL();
    void processInput();
};