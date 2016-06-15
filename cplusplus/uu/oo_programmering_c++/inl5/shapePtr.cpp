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
	if(ptr.shape) {
		shape = ptr.shape->clone();
		numshapes++;
	}
}

ShapePtr::~ShapePtr() {
	delete shape;
	numshapes--;
}

std::ostream& operator<<(std::ostream &output, const ShapePtr ptr) {
	if(ptr.shape) {
		output << ptr.shape->extractInfo();
	}	
	return output;
}

std::istream& operator>>(std::istream &input, ShapePtr &ptr) {
	
  std::string str;
	if(input >> str) {

   	str = str.substr(0, str.size()-1);
    
    if(str == "POLYGON") {
			ptr.shape = new Polygon();
    }   
    else if(str == "CIRCLE") {
			ptr.shape = new Circle();
    }   
    else if(str == "POINT") {
      ptr = new Point();
    }   
    else if(str == "RECTANGLE") {
      ptr.shape = new Rectangle();
    } 
		ptr.shape->read(input);
	}  
    	
	return input;
}

ShapePtr& ShapePtr::operator=(const ShapePtr &ptr) {
	if(this != &ptr && ptr.shape) {
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
