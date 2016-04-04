#ifndef SHAPE_H
#define SHAPE_H
#include "shape.h"
#endif
#include <iostream>

class Rectangle : public Shape
{
	public:
		Rectangle(double x, double y, double width, double height)
		{
			vert = Vertex(x,y);
			width = width;
			height = height;
		}

		double area()
		{
			return width*height;
		}

		void print()
		{
			std::cout << "type: Rectangle" << std::endl;
			std::cout << "x: " << getX() << std::endl;
			std::cout << "y: " << getY() << std::endl;
			std::cout << "size: " << area() << std::endl;
		}
		
	private:
		double width;
		double height;
};
