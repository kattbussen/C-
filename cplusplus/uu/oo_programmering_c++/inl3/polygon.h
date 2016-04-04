#ifndef SHAPE_H
#define SHAPE_H
#include "shape.h"
#endif
#include <iostream>
#include <cmath>

class Polygon : public Shape
{
	public:

		Polygon(double x, double y, Vertex *vertArr, int noVertices)
		{
			vert = Vertex(x,y);
			numberOfVertices = noVertices;

			vertArray = new Vertex[noVertices];
			for(int i = 0; i < noVertices; i++)
				add(vertArr[i]);
		}

		~Polygon()
		{
			delete[] vertArray;
		}

		void add(Vertex ver)
		{
			Vertex *tmpArray = new Vertex[numberOfVertices+1];
			for(int i = 0; i < numberOfVertices; i++)
				tmpArray[i] = vertArray[i];

			delete[] vertArray;
			tmpArray[numberOfVertices] = ver;
			numberOfVertices++;
			vertArray = tmpArray;
		}

		double area()
		{
			double sum = 0;
			for(int i = 0; i < numberOfVertices-1; i++)
			{
				double first = vertArray[i].getXpos() * vertArray[i+1].getYpos();
				double second = vertArray[i+1].getXpos() * vertArray[i].getYpos(); 
				sum += (first - second) / 2;
			}
			if(numberOfVertices > 0)
			{
				double first = vertArray[numberOfVertices].getXpos() * vertArray[0].getYpos();
				double second = vertArray[0].getXpos() * vertArray[numberOfVertices].getYpos();
				sum += (first - second) / 2;
			}	

			return std::abs(sum);
		}

		void print()
		{
		}

	private:
		int numberOfVertices;
		Vertex* vertArray;
};
