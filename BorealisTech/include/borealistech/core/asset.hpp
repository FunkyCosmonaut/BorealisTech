#pragma once
#include "borealistech/utils/objloader.hpp"
#include <vector>
#include <glm/glm.hpp>


class Asset{
public:
    Asset(const std::string& objFilePath);
    ~Asset();

    void Draw();

private:
    bool ParseFile(const std::string& filePath,
                    std::vector<GLfloat>& vertices,
                    std::vector<GLfloat>& texCoords,
                    std::vector<GLfloat>& normals);
    void SetupBuffers();

    GLuint VAO_;
    GLuint VBO_;
    std::vector<GLfloat> vertices_;


};