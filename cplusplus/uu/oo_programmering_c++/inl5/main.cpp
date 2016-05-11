#include "shapePtr.h"

int main() {
	ShapePtr pt;

	//Polygon* pol = new Polygon( 1, 4, varr, 4 );
  Rectangle* rect = new Rectangle( 4, 10, 2, 4);
  Circle* circ = new Circle( 5,5, 3);
  Point* point = new Point( 6, 7, 1 );

	pt.addFirst(rect);
	pt.addFirst(circ);
	pt.addFirst(point);

	pt.printVec();

	return 0;
}

