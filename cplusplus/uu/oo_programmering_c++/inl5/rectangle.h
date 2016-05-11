#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <iostream>

class Rectangle : public Shape {
	public:
		Rectangle(double x, double y, double width, double height);
		double area();
		void print();
		Rectangle* clone() const;
		
	private:
		double width;
		double height;
};
#endif
