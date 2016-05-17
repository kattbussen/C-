#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <iostream>

class Rectangle : public Shape {
	public:
		Rectangle(int x, int y, int width, int height);
		~Rectangle();
		int area();
		void print();
		Rectangle* clone() const;
		std::string extractInfo();
		
	private:
		int width;
		int height;
};
#endif
