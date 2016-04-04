#ifndef SHAPE_H
#define SHAPE_H
#include "shape.h"
#endif
#include <iostream>
#include <cmath>

class Circle : public Shape
{
	public:
		Circle(double x, double y, double radius);
		double area();
		void print();
		
	private:
		double radius;
};
