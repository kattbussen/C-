#ifndef SHAPELIST_H
#define SHAPELIST_H
#include "shapelist.h"
#endif

ShapeList::ShapeList()
{
	noOfElements = 0;
	list = 0;
}

ShapeList::ShapeList(const ShapeList &shapes)
{
	noOfElements = shapes.noOfElements;
	list = shapes.list;
}

ShapeList::~ShapeList()
{
	/*Node nod = *list;
	for(int i = 0; i < noOfElements-1; i++)
	{
		Node next = *nod.next;
		delete &nod;
		nod = next;
	}
	delete &nod;*/
	delete[] list;
}

/*ShapeList& ShapeList::operator=(const ShapeList &slist)
{
	if(this != &slist)
	{
		noOfElements = slist.noOfElements;
		delete[] list;
		list = new Node[noOfElements];
		for(int i = 0; i < noOfElements; i++)
			list[i] = slist.list[i];
	}
	return *this;
}*/

void ShapeList::add(const Shape& s)
{
	if(noOfElements == 0)
	{
		Node *tmp = new Node(s);
		list = tmp;
	}
	else
	{
		Node* tmp = list;
		for(int i = 0; i < noOfElements-1; i++)
		{
			tmp = tmp->next;	
		}
		Node *newNode = new Node(s);
		tmp->next = newNode;
	}
	noOfElements++;
}

void ShapeList::remove(const Vertex &v)
{
}

double ShapeList::area()
{
	double ar = 0;
	Node* tmp = list;
	for(int i = 0; i < noOfElements-1; i++)
	{
		ar += tmp->shape->area();
		tmp = tmp->next;
	}
	ar += tmp->shape->area();
	return ar;
}

void ShapeList::print()
{
	Node* tmp = list;
	for(int i = 0; i < noOfElements; i++)
	{
		tmp->shape->print();
		tmp = tmp->next;
	}
}
