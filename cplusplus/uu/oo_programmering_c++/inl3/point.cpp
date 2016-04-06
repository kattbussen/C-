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

void Point::print()
{
	std::cout << "type: Point" << std::endl;
	std::cout << "x: " << getX() << std::endl;
	std::cout << "y: " << getY() << std::endl;
	std::cout << "size: " << area() << std::endl;
}

/*Point copyP(Point p)
{
	Point p2 = p;
	return p2;
}

int main()
{
	double x = 3;
	double y = 5;

	Point p = Point(x, y, 1);
	p.print();
	
	Point p2 = copyP(p);
	p2.print();

	//Point p3 = p2;
	//p3.print();

	return 0;
}*/
