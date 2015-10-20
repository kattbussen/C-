#include "insertionSort.h"

/************************************************
*
* Implements insertionSort and measures the time
* it takes to sort the given array of integers.
*
************************************************/

void InsertionSort::sort(int arr[], int size)
{
	int sorted[size];

	startTimer();
	
	for(int i = 0; i < size; i++)
	{
		int minPos = 0;
		int min = INT_MAX;
		for(int j = 0; j < size; j++)
		{
			if(arr[j] < min)
			{
				min = arr[j];
				minPos = j;
			}
		}
		sorted[i] = arr[minPos];
		arr[minPos] = INT_MAX;
	}
	
	stopTimer();
	
	std::copy(sorted, sorted+size, arr);
}
