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
		tmp->shape->print();
		list = tmp;
	}
	else
	{
		//Node tmp = list[noOfElements-1];
		/*for(int i = 0; i < noOfElements; i++)
		{
			tmp++;	
		}*/
		Node *newNode = new Node(s);
		list[noOfElements-1].next = newNode;
		//tmp->next = newNode;
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
	std::cout << noOfElements << std::endl;
	Node tmp = *list;
	if(tmp.shape != NULL)
		std::cout << "inte null" << std::endl;

	for(int i = 0; i < noOfElements; i++)
	{
		list[i].shape->print();
	}
}
