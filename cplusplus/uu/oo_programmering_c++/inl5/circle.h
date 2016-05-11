#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <iostream>
#include <cmath>

class Circle : public Shape {
	public:
		Circle(double x, double y, double radius);
		double area();
		void print();
		Circle* clone() const;
		
	private:
		double radius;
};
#endif
