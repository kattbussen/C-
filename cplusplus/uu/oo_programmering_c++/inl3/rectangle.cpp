#include "rectangle.h"

Rectangle::Rectangle(double x, double y, double width, double height)
{
	vert = Vertex(x,y);
	this->width = width;
	this->height = height;
}

double Rectangle::area()
{
	return width*height;
}

void Rectangle::print()
{
	std::cout << "RECTANGLE: (" << vert.getXpos() << "," << vert.getYpos() << ") (" << width << "," << height << ")" << std::endl;
}

Rectangle* Rectangle::clone() const
{
	Rectangle* rect = new Rectangle(*this);
	return rect;
}
