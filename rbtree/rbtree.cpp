#include <iostream>
#include "rbtree.h"


//pop

//push
template <class T> void rbtree<T>::push(Node<T> node)
{
}

//print
template <class T> void rbtree<T>::print()
{
	std::cout << "hej" << std::endl;
}


//needed to avoid linker errors
template void rbtree<int>::print();

