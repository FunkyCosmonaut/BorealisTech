#include <glad/glad.h>
#include "impetus/core/engine.hpp"
#include "impetus/core/renderer.hpp"
#include "impetus/utils/shaderloader.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#define IMAGE_HEIGHT 600
#define IMAGE_WIDTH 800

Engine::Engine(int width, int height)
    : width(width), height(height){
    initializeGLFW();
    createWindow();
    initializeGLAD();
    configureOpenGL();
    renderer.Initialize(width,height);
}

Engine::~Engine() {
    glfwTerminate();
}

void Engine::run() {
    // Load your assets, shaders, and set up the scene
//========================================================
//Render.Initialize();

    renderer.Initialize(IMAGE_WIDTH,IMAGE_HEIGHT);
    // Render loop
//===========================================================================

    // Render loop
    while (!glfwWindowShouldClose(window)) {
       
        processInput();

//Render the scene==========================================================
// Draw the triangle
      renderer.RenderScene();
//===========================================================


        // Swap buffers and poll for events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
}

void Engine::initializeGLFW() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(-1);
    }
}

void Engine::createWindow() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);

    window = glfwCreateWindow(width, height, "Engine", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);
}

void Engine::initializeGLAD() {
    if (!gladLoadGLES2Loader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }
}

void Engine::configureOpenGL() {
    // Configure OpenGL settings, e.g., glEnable(GL_DEPTH_TEST);

    // Set up callback functions, e.g., glfwSetKeyCallback(window, key_callback);
}

void Engine::processInput() {
    // Process keyboard, mouse, and other input events

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

   /* for (int key : {GLFW_KEY_W, GLFW_KEY_A, GLFW_KEY_S, GLFW_KEY_D}) {
        if (glfwGetKey(window, key) == GLFW_PRESS)
            camera.ProcessKeyboard(key, deltaTime);
    }*/
}

