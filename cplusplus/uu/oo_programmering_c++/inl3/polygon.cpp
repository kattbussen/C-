#include "polygon.h"

Polygon::Polygon(double x, double y, Vertex *vertArr, int noVertices)
{
	vert = Vertex(x,y);
	numberOfVertices = noVertices;

	vertArray = new Vertex[noVertices];
	for(int i = 0; i < noVertices; i++)
		vertArray[i] = vertArr[i];
}

Polygon::~Polygon()
{
	delete[] vertArray;
}

Polygon::Polygon(const Polygon &p)
{
	if(this != &p)
	{
		vert = p.vert;
		numberOfVertices = p.numberOfVertices;
		vertArray = new Vertex[numberOfVertices];
		for(int i = 0; i < numberOfVertices; i++)
			vertArray[i] = p.vertArray[i];
  }
}

double Polygon::area()
{
	double sum = 0;
	for(int i = 0; i < numberOfVertices-1; i++)
	{
		double first = vertArray[i].getXpos() * vertArray[i+1].getYpos();
		double second = vertArray[i+1].getXpos() * vertArray[i].getYpos(); 
		sum += (first - second) / 2;
	}
	if(numberOfVertices > 0)
	{
		double first = vertArray[numberOfVertices].getXpos() * vertArray[0].getYpos();
		double second = vertArray[0].getXpos() * vertArray[numberOfVertices].getYpos();
		sum += (first - second) / 2;
	}	

	return std::abs(sum);
}

void Polygon::print()
{
	std::cout << "POLYGON: (" << vert.getXpos() << "," << vert.getYpos() << ") { ";
	for(int i = 0; i < numberOfVertices; i++)
	{
		std::cout << "(" << vertArray[i].getXpos() << "," << vertArray[i].getYpos() << ") ";	
	}
	std::cout << "}" << std::endl; 
}	

Polygon* Polygon::clone() const
{
	Polygon* poly = new Polygon(*this);
	return poly;
}
