#include <iostream>
#include <set>
#include <assert.h>
#include "rbtree.h"

//************************************************
// Help function. Creates a tree with N nodes.
//************************************************
Rbtree populateTree(int N)
{
	Rbtree tree(0);
	for(int i = 1; i < N; i++)
	{
		Node node(i);
		tree.push(node);
	}
	return tree;
}

//************************************************
// Check colors of tree beginning with Node node. 
// Ie red node has only black children and so on.
//************************************************
bool checkColors(std::shared_ptr<Node> node)
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
	Rbtree tree = populateTree(N);
	bool result = checkColors(tree.getRoot());
	assert(result = true);
}

//************************************************
// Create a tree with N elements.
// Check that the tree contains N elements. 
//************************************************
void assertCorrectNoOfElements(int N)
{
	Rbtree tree = populateTree(N);
	assert(N == tree.getElementCount());
}

//************************************************
// Create a tree with one element.
// Then check that the second pop returns null.
//************************************************
void assertEmptyPop()
{
	Rbtree tree = populateTree(1);
	std::shared_ptr<Node> root = tree.pop();
	std::shared_ptr<Node> nod = tree.pop();

	assert(nod == nullptr);
}

//************************************************
// Create a tree with set values.
// Add the values to a set.
// Remove values as they are popped.
// Check that the set is empty.
//************************************************
void assertValues()
{
	Rbtree tree = populateTree(10);
	std::set<int> valSet;

	for(int i = 0; i < 10; i++)
	{
		valSet.insert(i);
	}

	std::shared_ptr<Node> p = tree.pop();
	while(p != nullptr)
	{
		valSet.erase(p->getVal());
		p = tree.pop();
	}

	assert(valSet.empty() == true);
}

//************************************************
// Insert 10, 5 and 3 and check that depth=2
//************************************************
void assertDepth()
{
	Rbtree tree(10);
	tree.push(5);
	tree.push(3);

	assert(tree.getDepth() == 2);
}

//************************************************
// Insert 5 and 5 into a tree and assert that;
// Number of elemets = 2.
// root->leftChilds value is 5.
//************************************************
void assertSameValue()
{
	Rbtree tree(5);
	tree.push(5);
	std::shared_ptr<Node> root = tree.getRoot();
	
	assert(tree.getElementCount() == 2);
	assert(root->leftChild != nullptr);
	assert(root->leftChild->getVal() == 5);
}


int main()
{
	/*int value = 5;
	std::shared_ptr<Node> nod(new Node(value));
	std::shared_ptr<Node> nodL(new Node(value-1));
	std::shared_ptr<Node> nodR(new Node(value+1));
	
	nod->isBlack = true;
		
	nod->leftChild = nodL; 
	nod->rightChild = nodR;

	nodL->parent = nod;
	nodR->parent = nod;

	Rbtree tree(5);
	tree.print(nod);
	bool rightColors = checkColors(nod);
	std::cout << rightColors << std::endl;
	std::cout << tree.getRoot()->getVal() << std::endl;*/

	assertSameValue();
	assertDepth();
	assertCorrectColoring(10);
	assertCorrectNoOfElements(10);
	assertEmptyPop();
	assertValues();
}

