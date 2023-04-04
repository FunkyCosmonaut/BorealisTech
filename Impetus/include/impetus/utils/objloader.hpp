// ObjParser.h
#pragma once
#include <glad/glad.h>
#include <string>
#include <vector>
#include <glm/glm.hpp>


bool ParseFile(const std::string& path, 
                    std::vector<GLfloat>& out_vertices, 
                    std::vector<GLfloat>& out_uvs, 
                    std::vector<GLfloat>& out_normals);