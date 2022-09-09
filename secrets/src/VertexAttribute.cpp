#include "VertexAttribute.h"


void VertexAttribute::setBuffers(GLuint _vbo, GLuint _ebo)
{
    vbo.setID(_vbo);
    ebo.setID(_ebo);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo.getBuffer());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo.getBuffer());

    // Атрибут с координатами
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    // Атрибут с цветом
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}