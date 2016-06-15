#include "shapePtr.h"
#include <algorithm>
#include <fstream>
#include <list>
#include <iterator>

int ShapePtr::numshapes = 0;
std::vector<ShapePtr> shapevec;

void printVec() {
	std::vector<ShapePtr>::iterator it;
	for(it = shapevec.begin(); it != shapevec.end(); ++it) {
		std::cout << *it << std::endl;
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

void insertFirst(ShapePtr ptr) {
	std::vector<ShapePtr>::iterator it = shapevec.begin();
	shapevec.insert(it, ptr);
}

void removeElement(int position) {
	int count = 0;
	std::vector<ShapePtr>::iterator it;

	if(position < 0 || position >= shapevec.size()) {
		std::cout << "Unable to remove element, position out of bounds" << std::endl;
	}
	else {
		for(it = shapevec.begin(); it != shapevec.end(); ++it) {
			if(count == position) {
				shapevec.erase(it);
				return;
			}
			count++;
		}
	}
}

struct IsClose {
	const Vertex ver;
	IsClose(const Vertex& vert) : ver(vert) {
	}

	bool operator()(ShapePtr ptr) const {
		return ptr.shape->isClose(ver);
	}
};

void removeCloseTo(int x, int y) {
	shapevec.erase(remove_if(shapevec.begin(), shapevec.end(), IsClose( Vertex(x, y) )), shapevec.end());
}

int main() {
	
  Vertex varr[] = { Vertex(0,0), Vertex(10,0), Vertex(5,2), Vertex(5,5) };
 
 // Här antar jag att ShapePtr har en konstruktor som tar en parameter av
 // typen "Shape *" och att just denna konstruktor _inte_ gör djupkopiering
 // Andra konstruktorer ska göra djupkopiering.
  
	shapevec.push_back( ShapePtr(new Polygon(1, 4, varr, 4 )) );
	shapevec.push_back( ShapePtr(new Circle(5, 5, 4)) );
  shapevec.push_back( ShapePtr(new Rectangle(4, 10, 2, 4)) );
  shapevec.push_back( ShapePtr(new Point(6, 7, 1)) );

	/*
	removeElement(3);
  ShapePtr p = ShapePtr(new Circle(5, 5, 4));
	ShapePtr pt = ShapePtr(*(p.shape));
	p.shape->vert.setXpos(4);
	p.printElement();
	pt.printElement();
	*/	

	/*
	std::sort(shapevec.begin(), shapevec.end(), compareArea);
	std::sort(shapevec.begin(), shapevec.end(), compareX);
	std::sort(shapevec.begin(), shapevec.end(), compareY);
 	*/
  
	
	std::ofstream os("fil.dat");
  std::ostream_iterator<const ShapePtr> shapeout(os,"\n");
  copy( shapevec.begin(), shapevec.end(), shapeout);
  os.close();


  std::ifstream is("fil.dat");
	std::istream_iterator<ShapePtr> shapein(is), endofshapein;
  std::list<ShapePtr> shapelist(shapein, endofshapein);
  for (std::list<ShapePtr>::iterator it = shapelist.begin(); it != shapelist.end(); it++) { 
    std::cout << *it << std::endl;
		//std::cout << "hej" << std::endl;
	}
  shapevec.insert( shapevec.end(), shapelist.begin(), shapelist.end() );
  

  
	removeCloseTo(6, 7);

  std::ostream_iterator<const ShapePtr> shapecout(std::cout,"\n");
  std::cout << shapevec.size() << std::endl;
  std::cerr << ShapePtr::numshapes << std::endl; // numshapes är ett statiskt attribut 
                                        // som håller reda på antalet objekt genom 
                                        // inkrement i konstruktorer och
                                        // dekrement i destruktorn
  copy( shapevec.begin(), shapevec.end(), shapecout);

	return 0;
}

