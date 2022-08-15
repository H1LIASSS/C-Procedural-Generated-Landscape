#include "VertexAttribute.h"


void VertexAttribute::setBuffers(GLuint _vbo, GLuint _ebo)
{
    vbo.setID(_vbo);
    ebo.setID(_ebo);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo.getBuffer());
    //char d[3000];
    //glGetBufferSubData(GL_ARRAY_BUFFER, 1, sizeof(Point3) * 121, d);
    //std::cout << d;
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo.getBuffer());
    glBindVertexArray(0);
}