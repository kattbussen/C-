#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "rectangle.h"
#endif

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
	std::cout << "type: Rectangle" << std::endl;
	std::cout << "x: " << getX() << std::endl;
	std::cout << "y: " << getY() << std::endl;
	std::cout << "size: " << area() << std::endl;
}

/*int main()
{
	double x = 3;
	double y = 5;

	Rectangle r = Rectangle(x, y, 1, 1);
	r.print();
	
	Rectangle r2 = r;
	r2.print();

	Rectangle r3 = r2;
	r3.print();

	return 0;
}*/
