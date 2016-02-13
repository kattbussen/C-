#include "polygon.h"

Polygon::Polygon()
{
	numberOfVertices = 0;
	vertArray = 0;	
}

Polygon::Polygon(Vertex *vertArr, int noVertices)
{
	numberOfVertices = noVertices;
	vertArray = new Vertex[numberOfVertices];
}

Polygon::~Polygon()
{
	delete[] vertArray;
}

void Polygon::add(Vertex ver)
{

}

double Polygon::area()
{
	return 0;
}
	
int Polygon::minx()
{
	return 0;
}

int Polygon::maxx()
{
	return 0;
}

int Polygon::miny()
{
	return 0;
}

int Polygon::maxy()
{
	return 0;
}

int Polygon::numVertices()
{
	return numberOfVertices;
}
