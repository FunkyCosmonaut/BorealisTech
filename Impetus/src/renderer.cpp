#include "impetus/core/renderer.hpp"
#include "impetus/utils/shaderloader.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <GLFW/glfw3.h>


#define IMAGE_HEIGHT 600
#define IMAGE_WIDTH 800

Renderer::Renderer() {
    // Constructor
}

Renderer::~Renderer() {
    // Destructor
}

void Renderer::Initialize(int width, int height) {
    // Initialize shaders, VAOs, VBOs, etc.
    Camera camera(0.0f, 0.0f, 3.0f, 0.0f, 1.0f, 0.0f, -90.0f, 0.0f);

    std::string vertexShaderSource = LoadShaderSource("assets/triangle/triangle.vert");
    std::string fragmentShaderSource = LoadShaderSource("assets/triangle/triangle.frag");
    GLuint shaderProgram = CreateShaderProgram(vertexShaderSource, fragmentShaderSource);
    if (shaderProgram == 0) {
        std::cerr << "Failed to create shader program" << std::endl;
       // return -1;
    }

    glLinkProgram(shaderProgram);
    

       // Create the model, view, and projection matrices
    glm::mat4 model = glm::mat4(1.0f);
    /*glm::mat4 view = glm::lookAt(
        glm::vec3(0.0f, 0.0f, 5.0f), // Camera position
        glm::vec3(0.0f, 0.0f, 0.0f), // Target position
        glm::vec3(0.0f, 1.0f, 0.0f)  // Up vector
    );*/
    glm::mat4 projection = glm::perspective(
        glm::radians(70.0f), // Field of view
        (float)IMAGE_WIDTH / (float)IMAGE_HEIGHT,      // Aspect ratio
        0.1f,                 // Near clipping plane
        100.0f                // Far clipping plane
    );

    // Delete the shaders as they are no longer needed
   // glDeleteShader(vertexShader);
   // glDeleteShader(fragmentShader);

    // Create vertex data for the triangle
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

}

void Renderer::RenderScene() {
    // Bind shaders, set uniforms, draw objects, etc.
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(shaderProgram);
        //projstuff
        glm::mat4 view = camera.GetViewMatrix();
        GLint viewLoc = glGetUniformLocation(shaderProgram, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
        //GLint viewLoc = glGetUniformLocation(shaderProgram, "view");
        GLint projectionLoc = glGetUniformLocation(shaderProgram, "projection");

        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        //glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
        //projstuff
        
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
}
