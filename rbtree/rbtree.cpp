#include <iostream>
#include "rbtree.h"

//get root
template <class T> Node<T> Rbtree<T>::getRoot()
{
	return Rbtree<T>::root;
}

//pop


//push
template <class T> void Rbtree<T>::push(Node<T> node)
{
}

//get number of elemets in tree
template <class T> int Rbtree<T>::getElementCount()
{
	return elementCount;
}

//print
template <class T> void Rbtree<T>::print(std::shared_ptr<Node<T>> node)
{
	if(node->isBlack)
		std::cout << "Tree contains a black node with value ";
	else
		std::cout << "Tree contains a red node with value ";
 
	std::cout << node->getVal() << std::endl;

	if(node->leftChild != nullptr)
	{
		Rbtree<T>::print(node->leftChild);
	}
	if(node->rightChild != nullptr)
	{
		Rbtree<T>::print(node->rightChild);
	}	
}


//needed to avoid linker errors
template void Rbtree<int>::print(std::shared_ptr<Node<int>> node);
template Rbtree<int>::Rbtree(int val);
template Node<int> Rbtree<int>::getRoot();
