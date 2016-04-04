#ifndef SHAPE_H
#define SHAPE_H
#include "shape.h"
#endif
#include <iostream>

class Rectangle : public Shape
{
	public:
		Rectangle(double x, double y, double width, double height);
		double area();
		void print();
		
	private:
		double width;
		double height;
};
