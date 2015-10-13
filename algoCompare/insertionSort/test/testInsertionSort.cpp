#include <iostream>
#include <chrono>
#include "../insertionSort.h"

bool testGetTime()
{
	InsertionSort inSort;
	std::chrono::duration<double> time;
	int size = 1000;
	int arr[size];	

	for(int i = 0; i < size; i++)
		arr[i] = rand() % 100 + 1;
	inSort.sort(arr, size);

	time = inSort.getTime();
	
	if(time != std::chrono::high_resolution_clock::duration::zero())
	{
		std::cout << "testGetTime passed." << std::endl;
		return true;
	}
	else
	{
		std::cout << "testGetTime failed." << std::endl;
		return false;
	}
}

bool testSort()
{
	InsertionSort inSort;
	int size = 100;
	int arr[size];
	
	for(int i = 0; i < size; i++)
		arr[i] = rand() % 100 + 1;
	
	inSort.sort(arr, size);

	for(int i = 0; i < size-1; i++)
	{
		if(arr[i] > arr[i+1])
		{
			std::cout << "testSort failed." << std::endl;
			return false;
		}
	}
	std::cout << "testSort passed." << std::endl;
	return true;
}

int main()
{
	int passed = 0;
	int noOfTests = 2;

	if(testGetTime())
		passed++;

	if(testSort())
		passed++;

	std::cout << passed << " of " << noOfTests << " passed." << std::endl;
}

