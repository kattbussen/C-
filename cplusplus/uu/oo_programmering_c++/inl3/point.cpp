#ifndef POINT_H
#define POINT_H
#include "point.h"
#endif

Point::Point(double x, double y, double size)
{
	vert = Vertex(x,y);
	this->size = size;
}

double Point::area()
{
	return size;
}

Point* Point::clone() const
{
	Point* p = new Point(*this);
	return p;
}

void Point::print()
{
	std::cout << "POINT: (" << vert.getXpos() << "," << vert.getYpos() << ") " << area() << std::endl;
}

/*class Node
{   
	public:
		Node(const Shape &sh)
		{	   
			shape = sh.clone();
			shape->print();
		}   

		Shape* shape;
};*/  

/*void add(const Shape &s)
{
	Node *tmp = new Node(s);
	tmp->shape->print();
}

int main()
{
	double x = 3;
	double y = 5;

	add(Point(6,7,1));	

	return 0;
}*/
