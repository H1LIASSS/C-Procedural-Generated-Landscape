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
};