#include <glad/glad.h>
#include "impetus/core/renderer.hpp"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "impetus/utils/shaderloader.hpp"
#include "impetus/utils/objloader.hpp"

#define IMAGE_HEIGHT 600
#define IMAGE_WIDTH 800


Renderer::Renderer(Camera& camera) : camera_(camera), window_(nullptr) {}

Renderer::~Renderer() {
    glDeleteVertexArrays(1, &VAO_);
    glDeleteBuffers(1, &VBO_);
    glDeleteProgram(shaderProgram_);

    glfwTerminate();
}

bool Renderer::Initialize() {
    // Initialization code
    // Initialize GLFW and create a window
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);

    window_ = glfwCreateWindow(IMAGE_WIDTH, IMAGE_HEIGHT, "Impetus", nullptr, nullptr);
    if (!window_)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window_);
    if (!gladLoadGLES2Loader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return false;
    }
    
    //Escape callback, closes the program
    glfwSetKeyCallback(window_, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
});


    std::string vertexShaderSource = LoadShaderSource("assets/triangle/triangle.vert");
    std::string fragmentShaderSource = LoadShaderSource("assets/triangle/triangle.frag");

    // Create the shader program using the new shader loader functions
    shaderProgram_ = CreateShaderProgram(vertexShaderSource, fragmentShaderSource);
    if (shaderProgram_ == 0) {
        std::cerr << "Failed to create shader program" << std::endl;
        return false;
    }

    glLinkProgram(shaderProgram_);
    

       // Create the model, view, and projection matrices
    model_ = glm::mat4(1.0f);
    /*glm::mat4 view = glm::lookAt(
        glm::vec3(0.0f, 0.0f, 5.0f), // Camera position
        glm::vec3(0.0f, 0.0f, 0.0f), // Target position
        glm::vec3(0.0f, 1.0f, 0.0f)  // Up vector
    );*/
    projection_ = glm::perspective(
        glm::radians(70.0f), // Field of view
        (float)IMAGE_WIDTH / (float)IMAGE_HEIGHT,      // Aspect ratio
        0.1f,                 // Near clipping plane
        100.0f                // Far clipping plane
    );
  //  glm::mat4 view = camera.GetViewMatrix();
  // Camera doesn't update if its here

    // Delete the shaders as they are no longer needed
   // glDeleteShader(vertexShader);
   // glDeleteShader(fragmentShader);

    // Create vertex data for the triangle
    //std::vector<GLfloat> vertices;
    //std::vector<GLfloat> texCoords;
    //std::vector<GLfloat> normals;

    if (!ParseFile("assets/skeleton/skeleton.obj", vertices, texCoords, normals)) {
        std::cerr << "Failed to load the OBJ file. Terminating the application." << std::endl;
        std::exit(EXIT_FAILURE);
        }
    /*GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };*/

    glGenVertexArrays(1, &VAO_);
    glGenBuffers(1, &VBO_);

    glBindVertexArray(VAO_);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    return true;

}

void Renderer::RenderScene() {
    // Render loop code
    window_ = Renderer::GetWindow();
    float lastFrame = 0.0f;
    while (!glfwWindowShouldClose(window_))
    {

//===================================================================
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

    for (int key : {GLFW_KEY_W, GLFW_KEY_A, GLFW_KEY_S, GLFW_KEY_D}) {
        if (glfwGetKey(window_, key) == GLFW_PRESS)
            camera_.ProcessKeyboard(key, deltaTime);
    }
//===================================================================

        // Clear the screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the triangle
        glUseProgram(shaderProgram_);
        //projstuff
        glm::mat4 view_ = camera_.GetViewMatrix();
        GLint viewLoc = glGetUniformLocation(shaderProgram_, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view_));
        GLint modelLoc = glGetUniformLocation(shaderProgram_, "model");
        //GLint viewLoc = glGetUniformLocation(shaderProgram, "view");
        GLint projectionLoc = glGetUniformLocation(shaderProgram_, "projection");

        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model_));
        //glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection_));
        //projstuff
        
        glBindVertexArray(VAO_);
        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vertices.size() / 3));

        // Swap buffers and poll for events
        glfwSwapBuffers(window_);
        glfwPollEvents();
    }
}

GLFWwindow* Renderer::GetWindow() const {
    return window_;
}