#ifndef CIRCLE_H
#define CIRCLE_H
#include "circle.h"
#endif

Circle::Circle(double x, double y, double radius)
{
	vert = Vertex(x,y);
	this->radius = radius;
}

double Circle::area()
{
	return M_PI*radius*radius;
}

void Circle::print()
{
	std::cout << "CIRCLE: (" << vert.getXpos() << "," << vert.getYpos() << ") " << radius << std::endl;
}

Circle* Circle::clone() const
{
	Circle* circ = new Circle(*this);
	return circ;
}
