#include "Shader.h"

#include <fstream>
#include <string>

#include <iostream>

std::string loadData(std::string path)
{
    std::string sum;
    std::string line;

    std::ifstream shdr(path);
    while (std::getline(shdr, line)) { sum += (line + '\n'); };
    shdr.close();
    
    return sum;
}

Shader::Shader()
{
    //Load text
    std::string a = loadData("../vertexshader.glsl").c_str();
    std::string b = loadData("../fragmentshader.glsl").c_str();

    //Vertex shader
    const GLchar* vertexShaderSource = a.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    
    
    //Fragment shader
    const GLchar* fragmentShaderSource = b.c_str();

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    //Link shaders
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glUseProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}