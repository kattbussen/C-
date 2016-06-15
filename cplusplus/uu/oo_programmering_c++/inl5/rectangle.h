#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <iostream>

class Rectangle : public Shape {
	public:
		Rectangle();
		Rectangle(int x, int y, int width, int height);
		~Rectangle();
		int area();
		void print();
		Rectangle* clone() const;
		std::string extractInfo();
		std::istream& read(std::istream &input);
		
	private:
		int width;
		int height;
};
#endif
