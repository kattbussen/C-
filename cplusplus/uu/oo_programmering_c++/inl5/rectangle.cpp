#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height) {
	vert = Vertex(x,y);
	this->width = width;
	this->height = height;
}

Rectangle::~Rectangle() {
	delete this;
}

int Rectangle::area() {
	return width*height;
}

void Rectangle::print() {
	std::cout << "RECTANGLE: (" << vert.getXpos() << "," << vert.getYpos() << ") (" << width << "," << height << ")" << std::endl;
}

Rectangle* Rectangle::clone() const {
	Rectangle* rect = new Rectangle(*this);
	return rect;
}

std::string Rectangle::extractInfo() {
	return "RECTANGLE: (" + std::to_string(vert.getXpos()) + "," + std::to_string(vert.getYpos()) + ") (" + std::to_string(width) + "," + std::to_string(height) + ")";
}
