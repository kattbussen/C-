#ifndef SHAPE_H
#define SHAPE_H
#include "shape.h"
#endif
#include <iostream>
#include <cmath>

class Polygon : public Shape
{
	public:
		Polygon(double x, double y, Vertex *vertArr, int noVertices);
		~Polygon();
		Polygon(const Polygon &p);
		double area();
		void print();

	private:
		int numberOfVertices;
		Vertex* vertArray;
};
