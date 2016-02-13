#ifndef VERTEX_H
#define VERTEX_H
#include "vertex.h"
#endif

class Polygon
{
	private:
		Vertex *vertArray;
		int numberOfVertices;		
	
	public:
		Polygon();
		Polygon(Vertex *vertArr, int noVertices);
		~Polygon();
		void add(Vertex ver);
		double area();
		int minx();
		int maxx();
		int miny();
		int maxy();
		int numVertices();
};
