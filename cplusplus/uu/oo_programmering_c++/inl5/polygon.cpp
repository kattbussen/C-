#include "polygon.h"

Polygon::Polygon(int x, int y, Vertex *vertArr, int noVertices) {
	vert = Vertex(x,y);
	numberOfVertices = noVertices;

	vertArray = new Vertex[noVertices];
	for(int i = 0; i < noVertices; i++) {
		vertArray[i] = vertArr[i];
	}

	std::cout << "creating polygon" << std::endl;	
	numshapes++;
}

Polygon::~Polygon() {
	delete[] vertArray;
}

Polygon::Polygon(const Polygon &p) {
	if(this != &p) {
		vert = p.vert;
		numberOfVertices = p.numberOfVertices;
		vertArray = new Vertex[numberOfVertices];
		for(int i = 0; i < numberOfVertices; i++) {
			vertArray[i] = p.vertArray[i];
		}
  }
}

int Polygon::area() {
	int sum = 0;
	for(int i = 0; i < numberOfVertices-1; i++) {
		int first = vertArray[i].getXpos() * vertArray[i+1].getYpos();
		int second = vertArray[i+1].getXpos() * vertArray[i].getYpos(); 
		sum += (first - second) / 2;
	}
	if(numberOfVertices > 0) {
		int first = vertArray[numberOfVertices].getXpos() * vertArray[0].getYpos();
		int second = vertArray[0].getXpos() * vertArray[numberOfVertices].getYpos();
		sum += (first - second) / 2;
	}	

	return std::abs(sum);
}

void Polygon::print() {
	std::cout << "POLYGON: (" << vert.getXpos() << "," << vert.getYpos() << ") { ";
	for(int i = 0; i < numberOfVertices; i++) {
		std::cout << "(" << vertArray[i].getXpos() << "," << vertArray[i].getYpos() << ") ";	
	}
	std::cout << "}" << std::endl; 
}	

Polygon* Polygon::clone() const {
	Polygon* poly = new Polygon(*this);
	return poly;
}

std::string Polygon::extractInfo() {
	std::string tmp = "";
	tmp = "POLYGON: (" + std::to_string(vert.getXpos()) + "," + std::to_string(vert.getYpos()) +  ") { ";
	for(int i = 0; i < numberOfVertices; i++) {
		tmp += "(" + std::to_string(vertArray[i].getXpos()) + "," + std::to_string(vertArray[i].getYpos()) + ") ";	
	}
	tmp += "}"; 
	
	return tmp;
}
