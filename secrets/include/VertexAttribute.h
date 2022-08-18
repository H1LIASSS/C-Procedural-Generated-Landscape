#pragma once

#include "Buffer.h"

class VertexAttribute
{
public:
	VertexAttribute() {};

	void setBuffers(GLuint a, GLuint b);
	GLuint getVAO() { return vao; };
private:
	Buffer vbo;
	Buffer ebo;
	GLuint vao = -1;
protected:
};

//