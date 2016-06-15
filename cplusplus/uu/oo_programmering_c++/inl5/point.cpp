#include "point.h"

Point::Point() {
	size = 0;
}

Point::Point(int x, int y, int size) {
	vert = Vertex(x,y);
	this->size = size;
}

Point::~Point() {
}

int Point::area() {
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

std::istream& Point::read(std::istream &input) {
	int x, y, size;
  std::string substring;

  input >> substring;    
  x = std::stoi(substring.substr(1, substring.find(',')));
  y = std::stoi(substring.substr(substring.find(',')+1, substring.size()-1));
  input >> size;
  
  vert = Vertex(x, y); 
	this->size = size;
  return input;
}
