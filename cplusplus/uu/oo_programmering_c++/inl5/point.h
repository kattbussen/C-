#ifndef POINT_H
#define POINT_H

#include "shape.h"
#include <iostream>

class Point : public Shape {
	public:
		Point(double x, double y, double size);
		double area();
		Point* clone() const;
		void print();
		
	private:
		double size;
};
#endif
