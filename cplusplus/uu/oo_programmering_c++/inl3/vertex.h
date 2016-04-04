class Vertex
{
	public:
		Vertex()
		{
			xPos = 0;
			yPos = 0;
		}

		Vertex(double x, double y)
		{
			xPos = x;
			yPos = y;
		}

		~Vertex()
		{
		}

		double getXpos()
		{
			return xPos;
		}

		double getYpos()
		{
			return yPos;
		}

	private:
		double xPos;
		double yPos;
};
