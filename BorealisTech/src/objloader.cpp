#include <glad/glad.h>
#include "borealistech/utils/objloader.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <glm/glm.hpp>

bool ParseFile(const std::string& path, std::vector<GLfloat>& out_vertices, std::vector<GLfloat>& out_uvs, std::vector<GLfloat>& out_normals) {
    std::vector<glm::vec3> temp_vertices;
    std::vector<glm::vec2> temp_uvs;
    std::vector<glm::vec3> temp_normals;

    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Failed to open the OBJ file: " << path << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "v") {
            glm::vec3 vertex;
            iss >> vertex.x >> vertex.y >> vertex.z;
            temp_vertices.push_back(vertex);
        } else if (prefix == "vt") {
            glm::vec2 uv;
            iss >> uv.x >> uv.y;
            temp_uvs.push_back(uv);
        } else if (prefix == "vn") {
            glm::vec3 normal;
            iss >> normal.x >> normal.y >> normal.z;
            temp_normals.push_back(normal);
        } else if (prefix == "f") {
            std::string face_data;
            while (iss >> face_data) {
                std::replace(face_data.begin(), face_data.end(), '/', ' ');
                std::istringstream face_iss(face_data);

                unsigned int vertexIndex, uvIndex, normalIndex;
                face_iss >> vertexIndex >> uvIndex >> normalIndex;

                out_vertices.push_back(temp_vertices[vertexIndex - 1].x);
                out_vertices.push_back(temp_vertices[vertexIndex - 1].y);
                out_vertices.push_back(temp_vertices[vertexIndex - 1].z);

                out_uvs.push_back(temp_uvs[uvIndex - 1].x);
                out_uvs.push_back(temp_uvs[uvIndex - 1].y);

                out_normals.push_back(temp_normals[normalIndex - 1].x);
                out_normals.push_back(temp_normals[normalIndex - 1].y);
                out_normals.push_back(temp_normals[normalIndex - 1].z);
            }
        }
    }

    return true;
}