#include "circle.h"

Circle::Circle(double x, double y, double radius) {
	vert = Vertex(x,y);
	this->radius = radius;
}

double Circle::area() {
	return M_PI*radius*radius;
}

void Circle::print() {
	std::cout << "CIRCLE: (" << vert.getXpos() << "," << vert.getYpos() << ") " << radius << std::endl;
}

Circle* Circle::clone() const {
	Circle* circ = new Circle(*this);
	return circ;
}
