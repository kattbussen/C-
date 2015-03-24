#include "node.h"

class Rbtree
{
	public:
		Rbtree(int val) {
			rootP = std::shared_ptr<Node>(new Node(val));
		}
	
		void push(Node node);
		std::shared_ptr<Node> pop();
		void print(std::shared_ptr<Node> node);
		int getElementCount();
		std::shared_ptr<Node> getRoot();
		int getDepth();

	private:	
		std::shared_ptr<Node> rootP;
		int elementCount;
		int depth;
};
