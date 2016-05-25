#ifndef SHAPE_H
#define SHAPE_H

#include "vertex.h"
#include <string>
#include <iostream>
#include <cmath>

class Shape {
	public:
		Vertex vert;
		static int numshapes;

		Shape() { numshapes++; }

		virtual ~Shape() {
		}

		virtual int area() {
			return 0;
		}

		virtual void print() {
			std::cout << "type: unknown." << std::endl;
			std::cout << "x: unknown." << std::endl;
			std::cout << "y: unknown." << std::endl;
			std::cout << "size: unknown." << std::endl;
		}

		virtual Shape* clone() const {
			return NULL;
		}
	
		bool isClose(const Vertex ver) {
			int xdiff = std::abs(ver.getXpos() - getX());
			int ydiff = std::abs(ver.getYpos() - getY());
		
			if(xdiff < 1 && ydiff < 1)
				return true;
			else
				return false;
		}
	
		int getX() {
			return vert.getXpos();
		}

		int getY() {
			return vert.getYpos();
		}
	
		virtual std::string extractInfo() {
			return "Unknown.";
		}

	private:
};
#endif
