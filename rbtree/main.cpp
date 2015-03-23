#include <iostream>
#include "rbtree.h"

int main(){
	int value = 5;
	Node<int>* nod = new Node<int>(value);
	Node<int>* nodL = new Node<int>(value-1);
	Node<int>* nodR = new Node<int>(value+1);
	
	std::cout << nod->getVal() << nodL->getVal() << nodR->getVal() << std::endl;

	nod->isBlack = true;
	nod->leftChild = std::unique_ptr<Node<int>>(nodL);
	nod->rightChild = std::unique_ptr<Node<int>>(nodR);

	nodL->parent = std::shared_ptr<Node<int>>(nod);
	nodR->parent = std::shared_ptr<Node<int>>(nod);

	rbtree<int> tree;
	tree.print();
}
