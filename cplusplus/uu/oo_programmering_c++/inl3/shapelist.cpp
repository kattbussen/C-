#include "shapelist.h"

ShapeList::ShapeList()
{
	noOfElements = 0;
	list = 0;
}

ShapeList::ShapeList(const ShapeList &shapes)
{
	noOfElements = shapes.noOfElements;
	
	if(noOfElements != 0)
	{
		Node* oldList = shapes.list;
		Node* newList = newList = new Node(*(shapes.list->shape->clone()));
		list = newList;
		for(int i = 0; i < noOfElements-1; i++)
		{
			oldList = oldList->next;
			newList->next = new Node(*(oldList->shape->clone()));
			newList = newList->next;
		}
	}
}

ShapeList::~ShapeList()
{
	if(noOfElements < 2)
		delete list;
	else
	{
		Node* delNode = list;
		Node* nextNode = delNode->next;
		for(int i = 0; i < noOfElements-1; i++)
		{
			delete delNode;
			delNode = nextNode;
			nextNode = delNode->next;
		}
		delete delNode;
	}
}

ShapeList& ShapeList::operator=(const ShapeList &slist)
{
	if(this != &slist)
	{
		noOfElements = slist.noOfElements;
	
		if(noOfElements != 0)
		{
			delete[] list;
			Node* oldList = slist.list;
			Node* newList = new Node(*(slist.list->shape->clone()));
			list = newList;

			for(int i = 0; i < noOfElements-1; i++)
			{
				oldList = oldList->next;
				newList->next = new Node(*(oldList->shape->clone()));
				newList = newList->next;
			}
		}
	}
	return *this;
}

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
	Node* oldList = list;
	Node* newList;
	int newElementCount = 0;
	
	for(int i = 0; i < noOfElements; i++)
	{
		if(!oldList->shape->isClose(v))
		{
			std::cout << "inte nära!" << std::endl;
			if(newElementCount == 0)
			{
				newList = new Node(*(oldList->shape->clone()));
				oldList = oldList->next;
				list = newList;
			}
			else
			{
				newList->next = new Node(*(oldList->shape->clone()));
				newList = newList->next;
				oldList = oldList->next;
			}
			newElementCount++;
		}
		else
		{
			std::cout << "nära!" << std::endl;	
			oldList = oldList->next;
		}
	}
	noOfElements = newElementCount;
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
