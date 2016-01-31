#include "node.h"

class Rbtree
{
	public:
		Rbtree(int val) {
			rootP = std::shared_ptr<Node>(new Node(val));
			rootP->isBlack = true;
		}
	
		void insert(std::shared_ptr<Node> root, int value);
		std::shared_ptr<Node> del(int value);
		void print(std::shared_ptr<Node> node);
		int getElementCount();
		std::shared_ptr<Node> getRoot();
		int getDepth();
		std::shared_ptr<Node> search(std::shared_ptr<Node> startNode, int value);
	
	private:
		void insert_case1(std::shared_ptr<Node> node);	
		void insert_case2(std::shared_ptr<Node> node);	
		void insert_case3(std::shared_ptr<Node> node);	
		void insert_case4(std::shared_ptr<Node> node);	
		void insert_case5(std::shared_ptr<Node> node);	
		std::shared_ptr<Node> rootP;
		int elementCount;
		int depth;
};
