#ifndef SHAPE_H
#define SHAPE_H
#include "shape.h"
#endif

#ifndef POINT_H
#define POINT_H
#include "point.h"
#endif

#ifndef CIRCLE_H
#define CIRCLE_H
#include "circle.h"
#endif

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "rectangle.h"
#endif

#ifndef POLYGON_H
#define POLYGON_H
#include "polygon.h"
#endif

class ShapeList : public Shape
{
	public:
		ShapeList();
		ShapeList(const ShapeList &shapes);
		~ShapeList();
		//ShapeList& operator=(const ShapeList &slist);
		void add(const Shape& s);
		void remove(const Vertex &v);
		double area();
		void print();

	private:
		class Node
		{
			public:
				Node(Shape sh)
				{
					shape = &sh;
					//shape->print();
					next = 0;
				}

				void setNext(Node *nextNode)
				{
					next = nextNode;
				}
				Shape* shape;
				Node* next;
		};
		
		int noOfElements;
		Node *list;
};
