#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include <iostream>
#include <cmath>

class Polygon : public Shape {
	public:
		Polygon();
		Polygon(int x, int y, Vertex *vertArr, int noVertices);
		~Polygon();
		Polygon(const Polygon &p);
		int area();
		void print();
		Polygon* clone() const;
		std::string extractInfo();
		void add(Vertex ver);
		std::istream& read(std::istream &input);

	private:
		int numberOfVertices;
		Vertex* vertArray;
};
#endif
