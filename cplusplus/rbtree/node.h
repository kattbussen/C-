#include <memory>

struct Node {
	bool isBlack;

	std::shared_ptr<Node> leftChild;
	std::shared_ptr<Node> rightChild;	
	std::shared_ptr<Node> parent;

	Node(int val) : value(val) {}
	int getVal(){
		return value;
	}
	
	private:
		int value;
};
