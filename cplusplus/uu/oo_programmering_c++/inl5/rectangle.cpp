#include "rectangle.h"

Rectangle::Rectangle() {
	width = 0;
	height = 0;
}

Rectangle::Rectangle(int x, int y, int width, int height) {
	vert = Vertex(x,y);
	this->width = width;
	this->height = height;
}

Rectangle::~Rectangle() {
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

std::istream& Rectangle::read(std::istream &input) {
	int x, y, width, height;
  std::string substring;

  input >> substring;
  x = std::stoi(substring.substr(1, substring.find(',')));
  y = std::stoi(substring.substr(substring.find(',')+1, substring.size()-1));

  input >> substring;
  width = std::stoi(substring.substr(1, substring.find(',')));
  height = std::stoi(substring.substr(substring.find(',')+1, substring.size()-1));

  vert = Vertex(x,y);
	this->width = width;
	this->height = height;
	return input;
}
