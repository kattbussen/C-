#include "selectionSort.h"

/************************************************
*
* Implements selectionSort and measures the time
* it takes to sort the given array of integers.
*
************************************************/
int* SelectionSort::sort(int arr[], int size)
{
	startTimer();

	for(int i = 0; i < size; i++)
	{
		int min = INT_MAX;
		int minPos = 0;
		for(int j = i; j < size; j++)
		{
			if(arr[j] < min)
			{
				min = arr[j];
				minPos = j;
			}
		}
		arr[minPos] = arr[i];
		arr[i] = min;
	}
	
	stopTimer();
	
	return arr;
}
