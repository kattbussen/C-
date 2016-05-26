#include "shapePtr.h"

ShapePtr::ShapePtr() {
	shape = 0;
	numshapes++;
}

ShapePtr::ShapePtr(Shape* shp) {
	if(shp != 0) {
		shape = shp;
	}
	else {
		shape = 0;
	}
	numshapes++;	
}

ShapePtr::ShapePtr(Shape &shp) {
	shape = shp.clone();
	numshapes++;
}

ShapePtr::ShapePtr(const ShapePtr &ptr) {
	if (this != &ptr) {
		shape = ptr.shape->clone();
	}
	numshapes++;
}

ShapePtr::~ShapePtr() {
	delete shape;
	numshapes--;
}

std::ostream& operator<<(std::ostream &output, const ShapePtr ptr) {
	output << ptr.shape->extractInfo();
	return output;
}

std::istream& operator>>(std::istream &input, ShapePtr ptr) {
	input >> ptr.shape;
	return input;
}

ShapePtr& ShapePtr::operator=(const ShapePtr &ptr) {
	if(this != &ptr) {
		shape = ptr.shape->clone();
	}
	return *this;
}

void ShapePtr::printElement() {
	if (shape != 0) {
		shape->print();
	}
	else {
		std::cout << "ShapePtr contains no shape." << std::endl;
	}
}	
