#include "point.h"

Point::Point(double x, double y, double size) {
	vert = Vertex(x,y);
	this->size = size;
}

double Point::area() {
	return size;
}

Point* Point::clone() const {
	Point* p = new Point(*this);
	return p;
}

void Point::print() {
	std::cout << "POINT: (" << vert.getXpos() << "," << vert.getYpos() << ") " << area() << std::endl;
}

std::string Point::extractInfo() {
	return "POINT: (" + std::to_string(vert.getXpos()) + "," + std::to_string(vert.getYpos()) + ") " + std::to_string(area());
}
