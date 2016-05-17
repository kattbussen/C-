#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <iostream>
#include <cmath>

class Circle : public Shape {
	public:
		Circle(int x, int y, int radius);
		~Circle();
		int area();
		void print();
		Circle* clone() const;
		std::string extractInfo();

	private:
		int radius;
};
#endif
