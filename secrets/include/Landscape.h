#pragma once

#include "Mesh.h"

class Landscape : virtual public Mesh
{
public:
	Landscape(const int n);
	int& getVertecies() { return vertecies; };
protected:

private:
	int vertecies = 0;
};