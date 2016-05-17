#ifndef VERTEX_H
#define VERTEX_H
class Vertex {
	public:
		Vertex() {
			xPos = 0;
			yPos = 0;
		}

		Vertex(int x, int y) {
			xPos = x;
			yPos = y;
		}

		int getXpos() const {
			return xPos;
		}

		int getYpos() const {
			return yPos;
		}

		void setXpos(int newX) {
			xPos = newX;
		}

	private:
		int xPos;
		int yPos;
};
#endif
