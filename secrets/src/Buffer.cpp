#include "Buffer.h"

//Buffer::Buffer(std::vector<Point3>& data) //VBO
//{
//	glGenBuffers(1, &buffer);
//	glBindBuffer(GL_VERTEX_ARRAY, buffer);
//	glBufferData(GL_VERTEX_ARRAY, data.size(), data.data(), GL_DYNAMIC_DRAW);
//	glBindBuffer(GL_VERTEX_ARRAY, 0);
//}
//
//Buffer::Buffer(std::vector<GLint>& data) //EBO
//{
//	glGenBuffers(1, &buffer);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size(), data.data(), GL_DYNAMIC_DRAW);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//}

Buffer::~Buffer()
{
	glDeleteBuffers(1, &buffer);
}