#ifndef SHAPELIST_H
#define SHAPELIST_H
#include "shapelist.h"
#endif

ShapeList::ShapeList()
{
	noOfElements = 0;
}

ShapeList::ShapeList(const ShapeList &shapes)
{
}

ShapeList::~ShapeList()
{
	//delete[] list;
}

void ShapeList::add(const Shape& s)
{
	if(noOfElements == 0)
	{
		//Node tmp = new Node(s);
		delete[] list;
		list = new Node[1];
		//list[0] = new Node();
	}
	else
	{

	}
	noOfElements++;
}

void ShapeList::remove(const Vertex &v)
{
}

double ShapeList::area()
{
	double ar = 0;
	for(int i = 0; i < noOfElements; i++)
	{
		ar += list[i].shape->area();
	}
	return ar;
}

void ShapeList::print()
{
}
