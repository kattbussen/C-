#include <iostream>
#include "rbtree.h"

//get root
std::shared_ptr<Node> Rbtree::getRoot()
{
	return Rbtree::rootP;
}

//pop
std::shared_ptr<Node> Rbtree::pop()
{
	return Rbtree::rootP;
}

//push
void Rbtree::push(Node node)
{
}

//get number of elemets in tree
int Rbtree::getElementCount()
{
	return elementCount;
}

int Rbtree::getDepth()
{
	return depth;
}

//print
void Rbtree::print(std::shared_ptr<Node> node)
{
	if(node->isBlack)
		std::cout << "Tree contains a black node with value ";
	else
		std::cout << "Tree contains a red node with value ";
 
	std::cout << node->getVal() << std::endl;

	if(node->leftChild != nullptr)
	{
		Rbtree::print(node->leftChild);
	}
	if(node->rightChild != nullptr)
	{
		Rbtree::print(node->rightChild);
	}	
}

//needed to avoid linker errors
//template void Rbtree<int>::print(std::shared_ptr<Node<int>> node);
