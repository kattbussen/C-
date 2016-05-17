#ifndef POINT_H
#define POINT_H

#include "shape.h"
#include <iostream>

class Point : public Shape {
	public:
		Point(int x, int y, int size);
		~Point();
		int area();
		Point* clone() const;
		void print();
		std::string extractInfo();
		
	private:
		int size;
};
#endif
