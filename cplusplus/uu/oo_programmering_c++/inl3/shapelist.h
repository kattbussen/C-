#ifndef SHAPE_H
#define SHAPE_H
#include "shape.h"
#endif

#include "point.h"
#include "circle.h"
#include "rectangle.h"
#include "polygon.h"

class ShapeList : public Shape
{
	public:
		ShapeList()
		{
			noOfElements = 0;
		}
		
		ShapeList(const ShapeList &shapes)
		{
		}
		
		~ShapeList()
		{
			delete[] list;
		}

		void add(const Shape& s)
		{
			if(noOfElements == 0)
			{
				//Node tmp = new Node(s);
				delete[] list;
				list = new Node[1];
				list[0] = new Node();
			}
			else
			{

			}
			noOfElements++;
		}

		void remove(const Vertex &v)
		{
		}
		
		double area()
		{
			double ar = 0;
			for(int i = 0; i < noOfElements; i++)
			{
				ar += list[i].shape->area();
			}
			return ar;
		}
	
		void print()
		{
		}

	private:
		class Node
		{
			public:
				Node()
				{
				}

				Node(Shape shape)
				{
					shape = shape;
				}

				Shape* shape;
				Node* next;
		};
		
		int noOfElements;
		Node *list;
};
