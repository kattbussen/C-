#include <iostream>
#include "rbtree.h"

//get root
/*template <typename T> Node<T> Rbtree::getRoot()
{
	return Rbtree<T>::root;
}*/

//pop


//push
template <typename T> void Rbtree::push(Node<T> node)
{
}

//get number of elemets in tree
int Rbtree::getElementCount()
{
	return elementCount;
}

//print
template <typename T> void Rbtree::print(std::shared_ptr<Node<T>> node)
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
template void Rbtree::print(std::shared_ptr<Node<int>> node);
//template Rbtree<int>::Rbtree(int val);
//template Node<int> Rbtree<int>::getRoot();
