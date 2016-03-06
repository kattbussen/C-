#include "polygon.h"
#include <iostream>
#include <limits>
#include <cmath>

Polygon::Polygon()
{
	minX = INT_MAX;
	minY = INT_MAX;
	maxX = 0;
	maxY = 0;
	numberOfVertices = 0;
	vertArray = new Vertex[numberOfVertices];	
}

Polygon::Polygon(Vertex *vertArr, int noVertices)
{
	numberOfVertices = 0;
	minX = INT_MAX;
	minY = INT_MAX;
	maxX = 0;
	maxY = 0;
	vertArray = new Vertex[noVertices];
	for(int i = 0; i < noVertices; i++)
		add(vertArr[i]);
}

Polygon::~Polygon()
{
	delete[] vertArray;
}

Polygon& Polygon::operator=(const Polygon &p)
{
	if(this != &p)
	{
		delete[] vertArray;
		minX = p.minX;
		minY = p.minY;
		maxX = p.maxX;
		maxY = p.maxY;
		numberOfVertices = p.numberOfVertices;
		vertArray = new Vertex[numberOfVertices];
		for(int i = 0; i < numberOfVertices; i++)
			vertArray[i] = p.vertArray[i];
	}
	return *this;
}

Polygon::Polygon(const Polygon &p)
{
	if(this != &p)
	{
		minX = p.minX;
		minY = p.minY;
		maxX = p.maxX;
		maxY = p.maxY;
		numberOfVertices = p.numberOfVertices;
		vertArray = new Vertex[numberOfVertices];
		for(int i = 0; i < numberOfVertices; i++)
			vertArray[i] = p.vertArray[i];
	}
}

bool Polygon::operator>(const Polygon &s)
{
	return this->area() > s.area();
}

std::ostream& operator<<(std::ostream &output, Polygon &poly)
{
	output << "{";
	for(int i = 0; i < poly.numberOfVertices; i++)
	{
		output << "(" << poly.vertArray[i].getXpos() << "," << poly.vertArray[i].getYpos() << ") ";
	}
	output << "}";
	return output; 
}

void Polygon::compareMinMax(Vertex ver)
{
	int tmpX = ver.getXpos();
	int tmpY = ver.getYpos();
		
	if(tmpX > maxX)
		maxX = tmpX;
	if(tmpX < minX)
		minX = tmpX;

	if(tmpY > maxY)
		maxY = tmpY;
	if(tmpY < minY)
		minY = tmpY;
}

void Polygon::add(Vertex ver)
{
	Vertex *tmpArray = new Vertex[numberOfVertices+1];
	for(int i = 0; i < numberOfVertices; i++)
		tmpArray[i] = vertArray[i];

	delete[] vertArray;
	tmpArray[numberOfVertices] = ver;
	numberOfVertices++;
	vertArray = tmpArray;
	compareMinMax(ver);
}

double Polygon::area() const
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
	
int Polygon::minx()
{
	return minX;
}

int Polygon::maxx()
{
	return maxX;
}

int Polygon::miny()
{
	return minY;
}

int Polygon::maxy()
{
	return maxY;
}

int Polygon::numVertices()
{
	return numberOfVertices;
}

void Polygon::printVer()
{
	for(int i = 0; i < numberOfVertices; i++)
	{
		std::cout << "x: " << vertArray[i].getXpos() << ", y: " << vertArray[i].getYpos() << std::endl;
	}
}

