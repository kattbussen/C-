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

void ShapePtr::printElement() {
	if (shape != 0) {
		shape->print();
	}
	else {
		std::cout << "ShapePtr contains no shape." << std::endl;
	}
}	
