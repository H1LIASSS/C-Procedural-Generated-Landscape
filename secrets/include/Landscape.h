#pragma once

#include "Mesh.h"

class Landscape : virtual public Mesh
{
public:
	Landscape(int n);
	int& getTriangles() { return triangles; };
protected:

private:
	int triangles = 0;
};