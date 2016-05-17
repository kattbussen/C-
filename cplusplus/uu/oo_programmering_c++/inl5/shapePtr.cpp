#include "shapePtr.h"

ShapePtr::ShapePtr() {
	shape = 0;
}

ShapePtr::ShapePtr(Shape* shp) {
	shape = shp;
}

ShapePtr::ShapePtr(Shape &shp) {
	shape = shp.clone();
}

ShapePtr::~ShapePtr() {
		//delete *shape;
}

std::ostream& operator<<(std::ostream &output, ShapePtr ptr) {
	output << ptr.shape->extractInfo();
	return output;
}

ShapePtr& ShapePtr::operator=(const ShapePtr &ptr) {
	if(this != &ptr) {
		shape = ptr.shape->clone();
	}
	return *this;
}

ShapePtr::ShapePtr(const ShapePtr &ptr) {
	if (this != &ptr) {
		shape = ptr.shape->clone();
	}
}


void ShapePtr::printElement() {
	if (shape != 0) {
		shape->print();
	}
	else {
		std::cout << "ShapePtr contains no shape." << std::endl;
	}
}	
