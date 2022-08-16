#pragma once

#include "ElementBuffer.h"
#include "VertexBuffer.h"

class VertexAttribute
{
public:
	VertexAttribute() {};

	void setBuffers(GLuint a, GLuint b);
	GLuint getVAO() { return vao; };
private:
	VertexBuffer vbo;
	ElementBuffer ebo;
	GLuint vao = -1;
protected:
};

//