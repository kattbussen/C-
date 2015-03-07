#include <iostream>

void swapIntPoint(int* first, int* second)
{
	int tmp = *first;
	*first = *second;
	*second = tmp;
}

void swapIntRef(int& first, int& second)
{
	int tmp = first;
	first = second;
	second = tmp;
}

int main()
{
	int first = 1;
	int second = 2;

	std::cout << first << " " << second << std::endl;
	
	swapIntPoint(&first, &second);

	std::cout << first << " " << second << std::endl;
	
	swapIntRef(first, second);

	std::cout << first << " " << second << std::endl;
}

