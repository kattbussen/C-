#ifndef VERTEX_H
#define VERTEX_H
#include "vertex.h"
#endif

Vertex::Vertex()
{
}

Vertex::Vertex(int x, int y)
{
	xPos = x;
	yPos = y;
}

Vertex::~Vertex()
{
}

int Vertex::getXpos()
{
	return xPos;
}

int Vertex::getYpos()
{
	return yPos;
}
