#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Units.h"
#include <vector>


class Buffer
{
public:
	Buffer() {};
	~Buffer();
	GLuint& getBuffer() { return buffer; };
	void setID(GLuint _buffer) { buffer = _buffer; };
private:

protected:
	GLuint buffer = 0;
};
