#pragma once

#include "VertexAttribute.h"

class Mesh
{
public:
	GLuint getVAO() { return vao.getVAO(); };
protected:
	VertexAttribute vao;
private:
	//vertex
	//triangulize vertexes
	//vao
};