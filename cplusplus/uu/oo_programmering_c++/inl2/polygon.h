#include "vertex.h"

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
		void add(Vertex ver);
		double area();
		int minx();
		int maxx();
		int miny();
		int maxy();
		int numVertices();
		void printVer();
};

#endif
