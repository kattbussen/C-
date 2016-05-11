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
		std::vector<Shape*> vec;
		ShapePtr();

	private:

};
#endif
