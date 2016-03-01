#ifndef VERTEX_H
#define VERTEX_H
#include "vertex.h"
#endif

Vertex::Vertex()
{
	xPos = 0;
	yPos = 0;
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

/*Vertex& Vertex::operator=(const Vertex &v)
{
	if(this != &v)
	{
		xPos = v.xPos;
		yPos = v.yPos;
	}
	return *this;
}*/
