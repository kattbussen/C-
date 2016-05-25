#include "shapePtr.h"
#include <algorithm>
#include <fstream>
#include <list>

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

void read(std::istream &is) {

 	std::string str;

	while(is >> str) {
		str = str.substr(0, str.size()-1);
		
		if(str == "POLYGON") {
			int x, y, vertX, vertY;
			std::string substring;

			is >> substring;			
			x = std::stoi(substring.substr(1, substring.find(',')));
			y = std::stoi(substring.substr(substring.find(',')+1, substring.size()-1));

			//read the first vertice
			is >> substring;
			is >> substring;
			vertX = std::stoi(substring.substr(1, substring.find(',')));
			vertY = std::stoi(substring.substr(substring.find(',')+1, substring.size()-1));
			Vertex varr[1] = { Vertex(vertX, vertY) };
			Polygon *poly = new Polygon(x, y, varr, 1);
			
			//read additional vertices
			is >> substring;
			while(substring != "}") {
				vertX = std::stoi(substring.substr(1, substring.find(',')));
				vertY = std::stoi(substring.substr(substring.find(',')+1, substring.size()-1));
				poly->add(Vertex(vertX,vertY));
				is >> substring;
			}
			shapevec.push_back( ShapePtr(poly));
		}
		else if(str == "CIRCLE") {
			int x, y, radius;
			std::string substring;

			is >> substring;			
			x = std::stoi(substring.substr(1, substring.find(',')));
			y = std::stoi(substring.substr(substring.find(',')+1, substring.size()-1));
			is >> radius;
			
			shapevec.push_back( ShapePtr(new Circle(x, y, radius)) );	
		}
		else if(str == "POINT") {
			int x, y, size;
			std::string substring;

			is >> substring;			
			x = std::stoi(substring.substr(1, substring.find(',')));
			y = std::stoi(substring.substr(substring.find(',')+1, substring.size()-1));
			is >> size;
			
			shapevec.push_back( ShapePtr(new Point(x, y, size)) );	
		}
		else if(str == "RECTANGLE") {
			int x, y, width, height;
			std::string substring;
			
			is >> substring;
			x = std::stoi(substring.substr(1, substring.find(',')));
			y = std::stoi(substring.substr(substring.find(',')+1, substring.size()-1));
			
			is >> substring;
			width = std::stoi(substring.substr(1, substring.find(',')));
			height = std::stoi(substring.substr(substring.find(',')+1, substring.size()-1));
			
			shapevec.push_back( ShapePtr(new Rectangle(x, y, width, height)) );
		}
		else {
			std::cout << "läste okänd form" << std::endl;
		}
	}
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
	//read(is);
	  

	//std::istream_iterator<ShapePtr> shapein(is); //, endofshapein;
	std::istream_iterator<ShapePtr> endofshapein;
  //std::list<ShapePtr> shapelist(shapein, endofshapein );
  //for (std::list<ShapePtr>::iterator it = shapelist.begin(); it != shapelist.end(); it++) 
  //  std::cout << *it << std::endl;
  //shapevec.insert( shapevec.end(), shapelist.begin(), shapelist.end() );
  

  
	removeCloseTo(6, 7);

  std::ostream_iterator<const ShapePtr> shapecout(std::cout,"\n");
  std::cout << shapevec.size() << std::endl;
  std::cerr << Shape::numshapes << std::endl; // numshapes är ett statiskt attribut 
                                        // som håller reda på antalet objekt genom 
                                        // inkrement i konstruktorer och
                                        // dekrement i destruktorn
  copy( shapevec.begin(), shapevec.end(), shapecout);

	return 0;
}

