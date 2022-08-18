#include "Landscape.h"
#include "Units.h"
#include <iostream>

using namespace std;

Landscape::Landscape(const int n)
{
    vertecies = n * n * 8;

    std::vector<Point3> grid;
    const int g = n + 1;
    for (int i = 0; i < g; i++)
    {
        for (int j = 0; j < g; j++)
        {
            Point3 a;
            a.x = -1 + ((2.f / (n)) * (j));
            a.y = -1 + ((2.f / (n)) * (i));
            a.z = ((rand() % 100) / 100.f) - 1;
            grid.push_back(a);
        }
    } //Generate grid with random height vertex

    GLuint vb;
    glGenBuffers(1, &vb);
	glBindBuffer(GL_ARRAY_BUFFER, vb);
	glBufferData(GL_ARRAY_BUFFER, grid.size()*sizeof(Point3), grid.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


    std::vector<GLint> indicies;
    int z = 0;
    for (int i = 0; i < grid.size() - n - 2; i += 1)
    {
        if (z == n)
        {
            z = 0;
            continue;
        }
        indicies.push_back(i);
        indicies.push_back(i + g);
        indicies.push_back(i + 1);

        indicies.push_back(i + 1);
        indicies.push_back(i + g);
        indicies.push_back(i + g + 1);
        z++;
    }

    indicies;
    GLuint eb;
    glGenBuffers(1, &eb);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size()*sizeof(GLint), indicies.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    vao.setBuffers(vb, eb);

    //for (int i = 0; i < indicies.size(); i += 3)
    //    cout << ((i)/3)+1 <<":    "<< indicies[i] << ',' << indicies[i + 1] << ',' << indicies[i + 2] << endl;
}