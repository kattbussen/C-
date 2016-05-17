#ifndef SHAPEPTR_H
#define SHAPEPTR_H

#include <iostream>
#include <vector>
#include "shape.h"
#include "point.h"
#include "circle.h"
#include "rectangle.h"
#include "polygon.h"

class ShapePtr {
	public:
		ShapePtr();
		ShapePtr(Shape* shp);
		ShapePtr(Shape &shp);
		~ShapePtr();
		void printElement();
		Shape* shape;
		friend std::ostream& operator<<(std::ostream &output, ShapePtr ptr);
		ShapePtr(const ShapePtr &ptr);
		ShapePtr& operator=(const ShapePtr &ptr);
	
	private:
};
#endif
