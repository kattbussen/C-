#include "vertex.h"

class Shape
{
	public:
		Vertex vert;

		virtual double area() = 0;
		virtual void print() = 0;
		
		double getX()
		{
			return vert.getXpos();
		}

		double getY()
		{
			return vert.getXpos();
		}

	private:
};
