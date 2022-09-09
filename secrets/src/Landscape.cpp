#include "Landscape.h"
#include "Units.h"
#include <iostream>

using namespace std;

Landscape::Landscape(const int n)
{
    vertecies = n * n * 8;

    std::vector<Point3> vertexes;
    const int g = n + 1;

    Point3 v;
    Point3 c;
    for (int i = 0; i < g; i++)
    {
        for (int j = 0; j < g; j++)
        {
            
            v.x = -1 + ((2.f / (n)) * (j));
            v.z = -1 + ((2.f / (n)) * (i));
            v.y = ((rand() % 200) / 100.f)-1;
            vertexes.push_back(v);

            float h = v.y;
            if (h <= 1 && h >= 0.6) { c.x = 0; c.y = 0; c.z = 1; }
            else if (h <= 0.6 && h >= 0.2) { c.x = 0; c.y = 1; c.z = 0; }
            else if (h <= 0.2 && h >= -0.2) { c.x = 1; c.y = 0; c.z = 0; }
            else if (h <= -0.2 && h >= -0.6) { c.x = 0; c.y = 1; c.z = 0; }
            else { c.x = 0; c.y = 0; c.z = 1; };
            vertexes.push_back(c);
        }
    } //Generate grid with random height vertex

    GLuint vb;
    glGenBuffers(1, &vb);
	glBindBuffer(GL_ARRAY_BUFFER, vb);
	glBufferData(GL_ARRAY_BUFFER, vertexes.size()*sizeof(Point3), vertexes.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


    std::vector<GLint> indicies;
    int z = 0;
    for (int i = 0; i < vertexes.size() -((n*2)+2); i += 2)
    {
        if (z == n*2)
        {
            z = 0;
            continue;
        }
        indicies.push_back(i);
        indicies.push_back(i + (g*2));
        indicies.push_back(i + 2);

        indicies.push_back(i + 2);
        indicies.push_back(i + (g*2));
        indicies.push_back(i + (g*2)+2);
        z+=2;
    }

    GLuint eb;
    glGenBuffers(1, &eb);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size()*sizeof(GLint), indicies.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    vao.setBuffers(vb, eb);


    //for (int i = 0; i < indicies.size(); i += 3)
    //    cout << ((i)/3)+1 <<":    "<< indicies[i] << ',' << indicies[i + 1] << ',' << indicies[i + 2] << endl;
}