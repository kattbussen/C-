#include <iostream>
#include "rbtree.h"

int elementCount = 0;

//get root

//pop


//push
template <class T> void rbtree<T>::push(Node<T> node)
{
}

//get number of elemets in tree
int getElementCount()
{
	return elementCount;
}

//print
template <class T> void rbtree<T>::print(std::shared_ptr<Node<T>> node)
{
	if(node->isBlack)
		std::cout << "Tree contains a black node with value ";
	else
		std::cout << "Tree contains a red node with value ";
 
	std::cout << node->getVal() << std::endl;

	if(node->leftChild != nullptr)
	{
		rbtree<T>::print(node->leftChild);
	}
	if(node->rightChild != nullptr)
	{
		rbtree<T>::print(node->rightChild);
	}	
}


//needed to avoid linker errors
template void rbtree<int>::print(std::shared_ptr<Node<int>> node);

