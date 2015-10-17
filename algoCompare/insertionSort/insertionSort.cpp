#include "insertionSort.h"

int* InsertionSort::sort(int arr[], int size)
{
	int sorted[size];

	startTimer();
	
	for(int i = 0; i < size; i++)
	{
		int min = INT_MAX;
		for(int j = 0; j < size; j++)
		{
			if(arr[j] < min)
				min = j;
		}
		sorted[i] = min;
	}
	
	stopTimer();
	
	std::copy(sorted, sorted+size, arr);
	return arr;
}
