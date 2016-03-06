#include "vertex.h"
#include <iostream>

#ifndef POLYGON_H
#define POLYGON_H

class Polygon
{
	private:
		Vertex *vertArray;
		int numberOfVertices;		
		int maxX;
		int maxY;
		int minX;
		int minY;
		void compareMinMax(Vertex ver);
	
	public:
		Polygon();
		Polygon(Vertex *vertArr, int noVertices);
		~Polygon();
		Polygon& operator=(const Polygon &p);
		Polygon(const Polygon &p);
		bool operator>(const Polygon &s);
		friend std::ostream& operator<<(std::ostream &output, Polygon &poly);
		void add(Vertex ver);
		double area() const;
		int minx();
		int maxx();
		int miny();
		int maxy();
		int numVertices();
		void printVer();
};

#endif
