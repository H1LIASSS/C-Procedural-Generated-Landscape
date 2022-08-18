#pragma once

#include "glad/glad.h"

class Shader
{
public:
	Shader();
	GLuint& getShaderProgram() { return shaderProgram; };
protected:
private:
	GLuint shaderProgram;
	GLchar* vertexShaderSource = "#version 460 core\n"
		"layout (location = 0) in vec3 position;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
		"}\0";

	GLchar* fragmentShaderSource = "#version 460 core\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = vec4(0.0f, 1.0f, 0.0f, 1.0f);\n"
		"}\n\0";
};