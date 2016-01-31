#include <iostream>
#include "rbtree.h"

int main(){
	int value = 5;
	std::shared_ptr<Node<int>> nod(new Node<int>(value));
	std::shared_ptr<Node<int>> nodL(new Node<int>(value-1));
	std::shared_ptr<Node<int>> nodR(new Node<int>(value+1));
	
	std::cout << nod->getVal() << nodL->getVal() << nodR->getVal() << std::endl;

	nod->isBlack = true;
		
	std::cout << nod->getVal() << std::endl;
	
	nod->leftChild = nodL; 
	nod->rightChild = nodR;

	nodL->parent = nod;
	nodR->parent = nod;

	rbtree<int> tree;
	tree.print(nod);
}
