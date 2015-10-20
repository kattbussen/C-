#include <iostream>
#include <chrono>
#include "../insertionSort/insertionSort.h"
#include "../quickSort/quickSort.h"
#include "../selectionSort/selectionSort.h"

/*****************************************************
*
* Test the getTime function.
* Basic test, just checks that getTime returns
* a non-zero value.
*
*****************************************************/
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

/*****************************************************
*
* Test the sort function.
* Checks that given an array, the sort function
* returns an array where each value is smaller or equal
* to its predecessor.
*
*****************************************************/
bool testSortOrder(SortAlgorithm* sort)
{
	int size = 1000;
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

/*****************************************************
*
* Test the sort function.
* Checks that given an array, the sort function
* returns an array where each value is still represented.
*
*****************************************************/
bool testSortContent(SortAlgorithm* sort)
{
	int size = 100;
	int arr[size];
	int arrCopy[size];
	int checkSum = 0;	

	for(int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100 + 1;
		arrCopy[i] = arr[i];
	}

	sort->sort(arr, size);

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(arr[j] == arrCopy[i])
			{
				arrCopy[i] = 0;
				break;
			}
		}
	}

	for(int i = 0; i < size; i++)
		checkSum += arrCopy[i];
	
	if(checkSum != 0)
		return false;
	else
		return true;
}

/*****************************************************
*
* Main function.
* Runs the two tests above for the three implemented
* sorting algorithms and summarises the result. 
*
*****************************************************/
int main()
{
	int passed = 0;
	int totPassed = 0;
	int noOfTests = 3;
	int totNoOfTests = 9;


	std::cout << "#################################" << std::endl;
	std::cout << "# Testing InsertionSort         #" << std::endl;
	std::cout << "#################################" << std::endl;
	
	InsertionSort inSort;
	
	if(testGetTime(&inSort))
		passed++;
	if(testSortOrder(&inSort))
		passed++;
	if(testSortContent(&inSort))
		passed++;

	std::cout << passed << " of " << noOfTests << " passed." << std::endl;
	totPassed += passed;
	passed = 0;

	
	std::cout << "#################################" << std::endl;
	std::cout << "# Testing QuickSort             #" << std::endl;
	std::cout << "#################################" << std::endl;
	
	QuickSort qSort;
	
	if(testGetTime(&qSort))
		passed++;
	if(testSortOrder(&qSort))
		passed++;
	if(testSortContent(&qSort))
		passed++;
	
	std::cout << passed << " of " << noOfTests << " passed." << std::endl;
	totPassed += passed;
	passed = 0;	


	std::cout << "#################################" << std::endl;
	std::cout << "# Testing SelectionSort         #" << std::endl;
	std::cout << "#################################" << std::endl;
	
	SelectionSort selSort;
	
	if(testGetTime(&selSort))
		passed++;
	if(testSortOrder(&selSort))
		passed++;
	if(testSortContent(&selSort))
		passed++;
		
	std::cout << passed << " of " << noOfTests << " passed." << std::endl;
	totPassed += passed;
	passed = 0;

	std::cout << "#################################" << std::endl;
	std::cout << "# Test done                     #" << std::endl;
	std::cout << "#################################" << std::endl;
	
	std::cout << "Total: " << totPassed << " of " << totNoOfTests << " passed." << std::endl;
}
