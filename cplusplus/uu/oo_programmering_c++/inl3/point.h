#ifndef SHAPE_H
#define SHAPE_H
#include "shape.h"
#endif
#include <iostream>

class Point : public Shape
{
	public:
		Point(double x, double y, double size);
		double area();
		Point* clone() const;
		void print();
		
	private:
		double size;
};
