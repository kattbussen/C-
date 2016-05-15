#include "shapePtr.h"

ShapePtr::ShapePtr() {
	vec.clear();
}

ShapePtr::~ShapePtr() {
	std::vector<Shape*>::iterator it;
	for(it = vec.begin(); it != vec.end(); ++it) {
		delete *it;
	}	
}

void ShapePtr::addFirst(Shape* shape) {
	std::vector<Shape*>::iterator it = vec.begin();
	vec.insert(it, shape);
}

void ShapePtr::addLast(Shape* shape) {
	std::vector<Shape*>::iterator it = vec.end();
	vec.insert(it, shape);

}

void ShapePtr::printVec() {
	std::vector<Shape*>::iterator it;
	for(it = vec.begin(); it != vec.end(); ++it) {
		(*it)->print();
	}	
}	
