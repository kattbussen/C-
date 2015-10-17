#include <iostream>
#include <chrono>
#include "../insertionSort/insertionSort.h"
#include "../quickSort/quickSort.h"
#include "../selectionSort/selectionSort.h"

bool testGetTime(SortAlgorithm* sort)
{
	std::chrono::duration<double> time;
	int size = 1000;
	int arr[size];	

	for(int i = 0; i < size; i++)
		arr[i] = rand() % 100 + 1;
	
	sort->sort(arr, size);
	time = sort->getTime();
	
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

bool testSort(SortAlgorithm* sort)
{
	int size = 100;
	int arr[size];
	
	for(int i = 0; i < size; i++)
		arr[i] = rand() % 100 + 1;
	
	sort->sort(arr, size);

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
	int totPassed = 0;
	int noOfTests = 2;
	int totNoOfTests = 6;


	std::cout << "#################################" << std::endl;
	std::cout << "# Testing InsertionSort         #" << std::endl;
	std::cout << "#################################" << std::endl;
	
	InsertionSort inSort;
	
	if(testGetTime(&inSort))
		passed++;
	if(testSort(&inSort))
		passed++;

	std::cout << passed << " of " << noOfTests << " passed." << std::endl;
	totPassed += passed;
	passed = 0;
	
	std::cout << "#################################" << std::endl;
	std::cout << "# Test done                     #" << std::endl;
	std::cout << "#################################" << std::endl;
	

	std::cout << "#################################" << std::endl;
	std::cout << "# Testing QuickSort             #" << std::endl;
	std::cout << "#################################" << std::endl;
	
	QuickSort qSort;
	
	if(testGetTime(&qSort))
		passed++;
	if(testSort(&qSort))
		passed++;
	
	std::cout << passed << " of " << noOfTests << " passed." << std::endl;
	totPassed += passed;
	passed = 0;	

	std::cout << "#################################" << std::endl;
	std::cout << "# Test done                     #" << std::endl;
	std::cout << "#################################" << std::endl;
	

	std::cout << "#################################" << std::endl;
	std::cout << "# Testing SelectionSort         #" << std::endl;
	std::cout << "#################################" << std::endl;
	
	SelectionSort selSort;
	
	if(testGetTime(&selSort))
		passed++;
	if(testSort(&selSort))
		passed++;
		
	std::cout << passed << " of " << noOfTests << " passed." << std::endl;
	totPassed += passed;
	passed = 0;

	std::cout << "#################################" << std::endl;
	std::cout << "# Test done                     #" << std::endl;
	std::cout << "#################################" << std::endl;
	
	std::cout << "Total: " << totPassed << " of " << totNoOfTests << " passed." << std::endl;
}
