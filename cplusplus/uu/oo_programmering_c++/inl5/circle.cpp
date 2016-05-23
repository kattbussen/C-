#include "circle.h"

Circle::Circle(int x, int y, int radius) {
	vert = Vertex(x,y);
	this->radius = radius;
	std::cout << "creating circle" << std::endl;
	numshapes++;
}

Circle::~Circle() {
	std::cout << "deleting circle" << std::endl;
	numshapes--;
	std::cout << "Number of shapes left " << numshapes << std::endl;
}

int Circle::area() {
	return M_PI*radius*radius;
}

void Circle::print() {
	std::cout << "CIRCLE: (" << vert.getXpos() << "," << vert.getYpos() << ") " << radius << std::endl;
}

Circle* Circle::clone() const {
	Circle* circ = new Circle(*this);
	return circ;
}

std::string Circle::extractInfo() {
	return "CIRCLE: (" + std::to_string(vert.getXpos()) + "," + std::to_string(vert.getYpos()) + ") " + std::to_string(radius);
}
