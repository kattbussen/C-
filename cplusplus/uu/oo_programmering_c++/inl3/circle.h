#ifndef SHAPE_H
#define SHAPE_H
#include "shape.h"
#endif
#include <iostream>
#include <cmath>

class Circle : public Shape
{
	public:
		Circle(double x, double y, double radius)
		{
			vert = Vertex(x,y);
			radius = radius;
		}

		double area()
		{
			return M_PI*radius*radius;
		}

		void print()
		{
			std::cout << "type: Circle" << std::endl;
			std::cout << "x: " << getX() << std::endl;
			std::cout << "y: " << getY() << std::endl;
			std::cout << "size: " << area() << std::endl;
		}
		
	private:
		double radius;
};
