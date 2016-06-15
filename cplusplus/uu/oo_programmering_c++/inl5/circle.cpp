#include "circle.h"

Circle::Circle() {
	radius = 0;
}

Circle::Circle(int x, int y, int radius) {
	vert = Vertex(x,y);
	this->radius = radius;
}

Circle::~Circle() {
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

std::istream& Circle::read(std::istream &input) {
	int x, y, radius;
	std::string substring;
 
	input >> substring;
  x = std::stoi(substring.substr(1, substring.find(',')));
  y = std::stoi(substring.substr(substring.find(',')+1, substring.size()-1));
  input >> radius;

	vert = Vertex(x,y);
	this->radius = radius;
  return input;
}
