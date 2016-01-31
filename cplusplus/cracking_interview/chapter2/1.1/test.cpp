#include <iostream>

struct node
{
	node *next = NULL;
	int value = 666;
};

void myPrint(node nod)
{
	node *current = &nod;
	while(current->next != NULL)
	{
		std::cout << current->value << std::endl;
		current = current->next;
	}
	std::cout << current->value << std::endl;
}

bool contains(node nod, int value)
{
	node *current = &nod;
	while(current->next != NULL)
	{
		if(current->value == value)
			return true;

		current = current->next;
	}
	if(current-> value == value)
		return true;

	return false;
}

node removeDuplicates(node nod)
{
	node newHead;
	node *current = &nod;
	node *tmp = &newHead; 	

	while(current->next != NULL)
	{
		if(!contains(newHead, current->value))
		{
			node *newNode = new node;
			newNode->value = current->value;
			tmp->next = newNode;
			tmp = newNode;
		}
		current = current->next;
	}
	
	return newHead;
}

int main()
{
	node head;
	node *tmp = &head;
	
	for(int i = 0; i < 10; i++)
	{	
		if(i%2 == 0)
		{
			tmp->value = 0;
		}
		else
		{
			tmp->value = 1;
		}
		node *ny = new node;
		tmp->next = ny;
		tmp = ny;
	}

	myPrint(head);
	std::cout << "cleaning up." << std::endl;
	node cleanedNode = removeDuplicates(head);
	std::cout << "cleaned up." << std::endl;
	myPrint(cleanedNode);	
}

