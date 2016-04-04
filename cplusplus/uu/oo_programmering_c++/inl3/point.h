#ifndef SHAPE_H
#define SHAPE_H
#include "shape.h"
#endif
#include <iostream>

class Point : public Shape
{
	public:
		Point(double x, double y, double size)
		{
			vert = Vertex(x,y);
			size = size;
		}

		double area()
		{
			return size;
		}

		void print()
		{
			std::cout << "type: Point" << std::endl;
			std::cout << "x: " << getX() << std::endl;
			std::cout << "y: " << getY() << std::endl;
			std::cout << "size: " << area() << std::endl;
		}
		
	private:
		double size;
};
