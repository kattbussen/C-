#ifndef POINT_H
#define POINT_H
#include "point.h"
#endif

Point::Point(double x, double y, double size)
{
	vert = Vertex(x,y);
	this->size = size;
}

double Point::area()
{
	return size;
}

Point* Point::clone() const
{
	Point* p = new Point(*this);
	return p;
}

void Point::print()
{
	std::cout << "POINT: (" << vert.getXpos() << "," << vert.getYpos() << ") " << area() << std::endl;
}
