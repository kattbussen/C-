#include <iostream>
#include "tree.h"

template <typename T> void tree<T>::print(nod<T> no)
{
	std::cout << no.value << std::endl;
}

int main()
{
	nod<int> no;
	no.value = 5;

	tree<int> tr;

	tr.print(no);
}
