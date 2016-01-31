#include <iostream>
#include "rbtree.h"

//************************************************
// Get the root of the tree.
//************************************************
std::shared_ptr<Node> Rbtree::getRoot()
{
	return Rbtree::rootP;
}

//************************************************
// Del node with value.
//************************************************
std::shared_ptr<Node> Rbtree::del(int value)
{
	return Rbtree::rootP;
}

std::shared_ptr<Node> getGrandParent(std::shared_ptr<Node> node)
{
	if(node != nullptr && node->parent != nullptr)
		return node->parent->parent;
	else
		return nullptr;
}

std::shared_ptr<Node> getUncle(std::shared_ptr<Node> node)
{
	std::shared_ptr<Node> gParent = getGrandParent(node);
	if(gParent == nullptr)
		return nullptr;

	if(node->parent == gParent->leftChild)
		return gParent->rightChild;
	else
		return gParent->leftChild;
}

void Rbtree::insert_case5(std::shared_ptr<Node> node)
{
	std::cout << "case5 " << std::endl;
	
	/*if(node->leftChild == nullptr && node->rightChild == nullptr)
		std::cout << "node has no children" << std::endl;
	if(node->leftChild == nullptr)
		std::cout << "node has no left child" << std::endl;
	if(node->rightChild == nullptr)
		std::cout << "node has no right child" << std::endl;*/

	std::shared_ptr<Node> gParent = getGrandParent(node);
	
	node->parent->isBlack = true;
	gParent->isBlack = false;

	if(node == node->parent->leftChild)
	{
		std::shared_ptr<Node> savedRightNode = node->parent->rightChild;

		node->parent->parent = gParent->parent;
		node->parent->rightChild = gParent;
		gParent->leftChild = savedRightNode; 
		
		if(gParent->parent == nullptr)
		{
			rootP = node->parent;
		}
		else
		{
			if(gParent->parent->leftChild == gParent)
				gParent->parent->leftChild = node->parent;
			else
				gParent->parent->rightChild = node->parent;
		}
		gParent->parent = node->parent;
	}
	else
	{
		std::shared_ptr<Node> savedLeftNode = node->parent->leftChild;
	
		node->parent->parent = gParent->parent;
		node->parent->leftChild = gParent;
		gParent->rightChild = savedLeftNode;
		
		if(gParent->parent == nullptr)
		{	
			rootP = node->parent;
		}
		else
		{
			if(gParent->parent->leftChild == gParent)
				gParent->parent->leftChild = node->parent;
			else
				gParent->parent->rightChild = node->parent;
		}
		gParent->parent = node->parent;
	}
}

void Rbtree::insert_case4(std::shared_ptr<Node> node)
{
	std::cout << "case4" << std::endl;
	std::shared_ptr<Node> gParent = getGrandParent(node);
	
	if(node == node->parent->rightChild && node->parent == gParent->leftChild)
	{
		std::shared_ptr<Node> savedParent = gParent->leftChild;
		std::shared_ptr<Node> savedLeftNode = node->leftChild;

		gParent->leftChild = node;
		node->leftChild = savedParent;
		node->parent = gParent;
		savedParent->rightChild = savedLeftNode;	
		savedParent->parent = node;

		node = node->leftChild;
	}
	else if(node == node->parent->leftChild && node->parent == gParent->rightChild)
	{
		std::shared_ptr<Node> savedParent = gParent->rightChild;
		std::shared_ptr<Node> savedRightNode = node->rightChild;

		gParent->rightChild = node;
		node->rightChild = savedParent;
		node->parent = gParent;
		savedParent->leftChild = savedRightNode;
		savedParent->parent = node;		

		node = node->rightChild;
	}
	insert_case5(node);
}

void Rbtree::insert_case3(std::shared_ptr<Node> node)
{
	std::cout << "case3" << std::endl;
	std::shared_ptr<Node> uncle = getUncle(node);

	if(uncle != nullptr && !uncle->isBlack)
	{
		node->parent->isBlack = true;
		uncle->isBlack = true;
		std::shared_ptr<Node> gParent = getGrandParent(node);
		gParent->isBlack = false;
		insert_case1(gParent);
	}
	else
		insert_case4(node);
}

void Rbtree::insert_case2(std::shared_ptr<Node> node)
{
	std::cout << "case2" << std::endl;
	if(node->parent->isBlack)
		return;
	else
		insert_case3(node);
}

void Rbtree::insert_case1(std::shared_ptr<Node> node)
{
	std::cout << "case1" << std::endl;
	if(node->parent == nullptr)
		node->isBlack = true;
	else
		insert_case2(node);
}

//************************************************
// Insert
//************************************************
void Rbtree::insert(std::shared_ptr<Node> root, int value)
{
	if(root->getVal() > value && root->leftChild != nullptr)
	{
		insert(root->leftChild, value);	
	}
	else if(root->getVal() <= value && root->rightChild != nullptr)
	{
		insert(root->rightChild, value);
	}
	else if(root->getVal() > value)
	{
		std::shared_ptr<Node> node(new Node(value));
		node->isBlack = false;
		root->leftChild = node;
		node->parent = root;
		std::cout << "inserting " << value << " as a leftchild " << root->getVal() << "."  << std::endl;
	
		insert_case1(node);	
	}
	else
	{
		std::shared_ptr<Node> node(new Node(value));
		node->isBlack = false;
		root->rightChild = node;
		node->parent = root;
		std::cout << "inserting " << value << " as a rightchild of " << root->getVal() << "."  << std::endl;
		
		insert_case1(node);
	}
	elementCount++;
}

//************************************************
// Searches for node with value.
//************************************************
std::shared_ptr<Node> Rbtree::search(std::shared_ptr<Node> startNode, int value)
{
	if(startNode->getVal() == value)
	{
		return startNode;
	}
	else if(startNode->getVal() > value && startNode->leftChild != nullptr)
	{
		search(startNode->leftChild, value);
	}
	else if(startNode->rightChild != nullptr)
	{
		search(startNode->rightChild, value);
	}
	else
	{
		return nullptr;
	}
}

//************************************************
// Get number of elemets in tree.
//************************************************
int Rbtree::getElementCount()
{
	return elementCount;
}

//************************************************
// Get the depth of the tree. 
//************************************************
int Rbtree::getDepth()
{
	return depth;
}

//************************************************
// Print the tree.
//************************************************
void Rbtree::print(std::shared_ptr<Node> node)
{
	if(node->isBlack)
		std::cout << "Tree contains a black node with value ";
	else
		std::cout << "Tree contains a red node with value ";
 
	std::cout << node->getVal() << std::endl;

	if(node->leftChild != nullptr)
	{
		std::cout << "node with value " << node->getVal() << " has a left child." << std::endl;
		Rbtree::print(node->leftChild);
	}
	if(node->rightChild != nullptr)
	{
		std::cout << "node with value " << node->getVal() << " has a right child." << std::endl;
		Rbtree::print(node->rightChild);
	}	
}

//needed to avoid linker errors
//template void Rbtree<int>::print(std::shared_ptr<Node<int>> node);
