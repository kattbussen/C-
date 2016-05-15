#include "shapePtr.h"
#include <algorithm>

std::vector<ShapePtr> shapevec;

void printVec() {
	std::vector<ShapePtr>::iterator it;
	for(it = shapevec.begin(); it != shapevec.end(); ++it) {
		it->printElement();
		//std::cout << it->shape->area() << std::endl;
	}
}

bool compareX(ShapePtr first, ShapePtr second) {
	return first.shape->getX() < second.shape->getX();
}

bool compareY(ShapePtr first, ShapePtr second) {
	return first.shape->getY() < second.shape->getY();
}

bool compareArea(ShapePtr first, ShapePtr second) {
	return first.shape->area() < second.shape->area();
}

int main() {
	
  Vertex varr[] = { Vertex(0,0), Vertex(10,0), Vertex(5,2), Vertex(5,5) };
 
 // Här antar jag att ShapePtr har en konstruktor som tar en parameter av
 // typen "Shape *" och att just denna konstruktor _inte_ gör djupkopiering
 // Andra konstruktorer ska göra djupkopiering.
  shapevec.push_back( ShapePtr(new Polygon(1, 4, varr, 4 )) );
  shapevec.push_back( ShapePtr(new Circle(5, 5, 4)) );
  shapevec.push_back( ShapePtr(new Rectangle(4, 10, 2, 4)) );
  shapevec.push_back( ShapePtr(new Point(6,7,1)) );

	printVec();
	std::cout << "===============" << std::endl;
	std::sort(shapevec.begin(), shapevec.end(), compareArea);
	printVec(); 
	std::cout << "===============" << std::endl;
	std::sort(shapevec.begin(), shapevec.end(), compareX);
	printVec(); 
	std::cout << "===============" << std::endl;
	std::sort(shapevec.begin(), shapevec.end(), compareY);
	printVec(); 
 
  /*ofstream os("fil.dat");
  ostream_iterator<const ShapePtr> shapeout(os,"\n");
  copy( shapevec.begin(), shapevec.end(), shapeout);
  os.close();

  ifstream is("fil.dat");
  istream_iterator<ShapePtr> shapein(is), endofshapein;
  
  list<ShapePtr> shapelist(shapein, endofshapein );
  for (list<ShapePtr>::iterator it = shapelist.begin(); 
       it != shapelist.end(); it++) 
    cout << *it << endl;
  shapevec.insert( shapevec.end(), shapelist.begin(), shapelist.end() );
  
  shapevec.erase(remove_if( shapevec.begin(), shapevec.end(), 
			    CloseTo( Vertex(6,7))),
		 shapevec.end()); 

  ostream_iterator<const ShapePtr> shapecout(cout,"\n");
  cout << shapevec.size() << endl;
  cerr << ShapePtr:: numshapes << endl; // numshapes är ett statiskt attribut 
                                        // som håller reda på antalet objekt genom 
                                        // inkrement i konstruktorer och
                                        // dekrement i destruktorn
  copy( shapevec.begin(), shapevec.end(), shapecout);
	*/


	/*ShapePtr pt;

	//Polygon* pol = new Polygon( 1, 4, varr, 4 );
  Rectangle* rect = new Rectangle( 4, 10, 2, 4);
  Circle* circ = new Circle( 5,5, 3);
  Point* point = new Point( 6, 7, 1 );

	pt.addFirst(rect);
	pt.addFirst(circ);
	pt.addFirst(point);

	pt.printVec();
	*/
	return 0;
}

