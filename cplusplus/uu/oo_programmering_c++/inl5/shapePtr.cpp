#include "shapePtr.h"

ShapePtr::ShapePtr() {
	shape = 0;
}

ShapePtr::ShapePtr(Shape* shp) {
	shape = shp;
}

ShapePtr::~ShapePtr() {
		//delete shape;
}

std::ostream& operator<<(std::ostream &output, ShapePtr ptr) {
	output << ptr.shape->extractInfo();
	return output;
}

void ShapePtr::printElement() {
	if (shape != 0) {
		shape->print();
	}
	else {
		std::cout << "ShapePtr contains no shape." << std::endl;
	}
}	
