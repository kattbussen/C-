#include "vertex.h"
#include <string>
#include <iostream>

class Shape
{
	public:
		Vertex vert;

		virtual double area()
		{
			return 0;
		}

		virtual void print() 
		{
			std::cout << "type: unknown." << std::endl;
			std::cout << "x: unknown." << std::endl;
			std::cout << "y: unknown." << std::endl;
			std::cout << "size: unknown." << std::endl;
		}
	
		virtual Shape* clone() const
		{
			return NULL;
		}
	
		double getX()
		{
			return vert.getXpos();
		}

		double getY()
		{
			return vert.getYpos();
		}

	private:
};
