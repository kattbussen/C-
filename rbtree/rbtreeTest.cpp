#include <iostream>
#include <assert.h>
#include "rbtree.h"

//pop empty tree

//insert x items, then pop and check that they are the same

//helperFunction, creates tree<int> with N nodes
std::shared_ptr<Node<int>> populateTree(int N)
{
	for(int i = 0; i < N; i++)
	{
		Node<int> node(i);
	}
	std::shared_ptr<Node<int>> p(new Node<int>(N));
	return p;
}

//check colors of tree, ie red node has only black children and so on
bool checkColors(std::shared_ptr<Node<int>> node)
{
	bool parentCol = true;
	bool currCol = false;
	bool result = true;

	if(node->parent != nullptr)
	{
		currCol = node->isBlack;
		parentCol = node->parent->isBlack;
	}

	if(node->leftChild != nullptr)
		result = result && checkColors(node->leftChild);
	
	if(node->rightChild != nullptr)
		result = result && checkColors(node->rightChild);

	return result && (parentCol^currCol);
}

//************************************************
// Create a tree with N elements.
// Check that the coloring of nodes are correct.
//************************************************
void assertCorrectColoring(int N)
{
	std::shared_ptr<Node<int>> p = populateTree(N);
	bool result = checkColors(p);
	assert(result=true);
}

//************************************************
// Create a tree with N elements.
// Check that the tree contains N elements. 
//************************************************
void assertCorrectNoOfElements(int N)
{
	std::shared_ptr<Node<int>> p = populateTree(N);
	//assert();
}

int countElements(std::shared_ptr<Node<int>> node)
{
	return 0;
}

//check depth of tree, diff between min and max should be no more than 1


int main()
{
	int value = 5;
	std::shared_ptr<Node<int>> nod(new Node<int>(value));
	std::shared_ptr<Node<int>> nodL(new Node<int>(value-1));
	std::shared_ptr<Node<int>> nodR(new Node<int>(value+1));
	
	nod->isBlack = true;
		
	nod->leftChild = nodL; 
	nod->rightChild = nodR;

	nodL->parent = nod;
	nodR->parent = nod;

	Rbtree<int> tree(value);
	//tree.print(nod);
	bool rightColors = checkColors(nod);
	std::cout << rightColors << std::endl;
	std::cout << tree.getRoot().getVal() << std::endl;
}

