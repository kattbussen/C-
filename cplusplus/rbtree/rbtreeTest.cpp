#include <iostream>
#include <set>
#include <limits>
#include <assert.h>
#include "rbtree.h"

//************************************************
// Help function. Creates a tree with N nodes.
//************************************************
Rbtree populateTree(int N)
{
	Rbtree tree(0);
	std::shared_ptr<Node> root = tree.getRoot();
	for(int i = 1; i < N; i++)
	{
		tree.insert(root, i);
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
// Then check that the second del returns null.
//************************************************
void assertEmptyPop()
{
	Rbtree tree = populateTree(1);
	std::shared_ptr<Node> root = tree.del(0);
	std::shared_ptr<Node> nod = tree.del(0);

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

	std::shared_ptr<Node> p = tree.del(tree.getRoot()->getVal());
	while(p != nullptr)
	{
		valSet.erase(p->getVal());
		p = tree.del(tree.getRoot()->getVal());
	}

	assert(valSet.empty() == true);
}

//************************************************
// Insert 10, 5 and 3 and check that depth=2
//************************************************
void assertDepth()
{
	Rbtree tree(10);
	std::shared_ptr<Node> root = tree.getRoot();
	tree.insert(root, 5);
	tree.insert(root, 3);

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
	std::shared_ptr<Node> root = tree.getRoot();
	tree.insert(root, 5);
	
	assert(tree.getElementCount() == 2);
	assert(root->leftChild != nullptr);
	assert(root->leftChild->getVal() == 5);
}

//************************************************
// Assert binary tree property.
//************************************************
bool checkProperty(std::shared_ptr<Node> node, int minValue, int maxValue)
{
	if(node == nullptr)
		return true;

	if(node->getVal() < minValue || node->getVal() > maxValue)
		return false;

	return checkProperty(node->leftChild, minValue, node->getVal()) && checkProperty(node->rightChild, node->getVal(), maxValue);
}

void assertBinaryProperty()
{
	Rbtree tree = populateTree(100);
	//assert(checkProperty(tree.getRoot(), std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) == true);
}

//************************************************
// Assert binary tree property after deletion.
//************************************************
void assertPropAfterDelete()
{
	Rbtree tree = populateTree(100);
	assert(checkProperty(tree.getRoot(), std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) == true);
	assert(checkColors(tree.getRoot()) == true);
	tree.del(95);
	assert(checkProperty(tree.getRoot(), std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) == true);
	assert(checkColors(tree.getRoot()) == true);
}


//************************************************
//test search function
//************************************************
/*void assertSearch()
{
	Rbtree tree = populateTree(100);
	for(int i = 0; i < 100; i++)
	{
		assert(tree.)
	}
}*/


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

	/*assertSameValue();
	assertDepth();
	assertCorrectColoring(10);
	assertCorrectNoOfElements(10);
	assertEmptyPop();
	assertValues();
	assertBinaryProperty();
	assertPropAfterDelete();
	*/

	Rbtree tree(0); //0-3-1
	std::shared_ptr<Node> root = tree.getRoot();
	tree.insert(root, 3);
	tree.insert(root, 1);
	//tree.insert(root, 3);
	//tree.insert(root, 4);
	root = tree.getRoot();
	tree.print(root);
	/*tree.insert(root, 3);
	//tree.insert(root, 6);
	tree.print(root);
	*///assertBinaryProperty();

	//tree.insert(root, 1);
	//tree.print(root);
}

