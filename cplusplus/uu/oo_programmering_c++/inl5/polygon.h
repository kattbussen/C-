#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include <iostream>
#include <cmath>

class Polygon : public Shape {
	public:
		Polygon(double x, double y, Vertex *vertArr, int noVertices);
		~Polygon();
		Polygon(const Polygon &p);
		double area();
		void print();
		Polygon* clone() const;

	private:
		int numberOfVertices;
		Vertex* vertArray;
};
#endif
