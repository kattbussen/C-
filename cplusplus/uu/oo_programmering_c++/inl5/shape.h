#ifndef SHAPE_H
#define SHAPE_H

#include "vertex.h"
#include <string>
#include <iostream>
#include <cmath>

class Shape {
	public:
		Vertex vert;

		virtual double area() {
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
			double xdiff = std::abs(ver.getXpos() - getX());
			double ydiff = std::abs(ver.getYpos() - getY());
		
			if(xdiff < 1 && ydiff < 1)
				return true;
			else
				return false;
		}
	
		double getX() {
			return vert.getXpos();
		}

		double getY() {
			return vert.getYpos();
		}
	
		virtual std::string extractInfo() {
			return "Unknown.";
		}

	private:
};
#endif
