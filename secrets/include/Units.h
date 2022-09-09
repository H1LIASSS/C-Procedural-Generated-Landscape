#pragma once

#include "GLFW/glfw3.h"

struct Color
{
    GLuint r = 255, g = 255, b = 255; /*White as default color*/
};

struct Point3 /*3d unit*/
{
    GLfloat x = 0, y = 0, z = 0;
};
