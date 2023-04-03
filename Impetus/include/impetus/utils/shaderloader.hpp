#pragma once

#include <glad/glad.h>
#include <string>

GLuint LoadShader(GLenum shaderType, const std::string& shaderSource);
GLuint CreateShaderProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
std::string LoadShaderSource(const std::string& filePath);