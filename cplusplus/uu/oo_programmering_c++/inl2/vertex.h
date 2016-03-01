#ifndef VERTEX_H
#define VERTEX_H

class Vertex
{
	private:
		int xPos;
		int yPos;

	public:
		Vertex();
		Vertex(int x, int y);		
		~Vertex();
		int getXpos();
		int getYpos();
		//Vertex& operator=(const Vertex &v);
};

#endif
