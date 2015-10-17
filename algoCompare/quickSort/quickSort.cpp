#include "quickSort.h"

int* QuickSort::sort(int arr[], int size)
{
	int sorted[size];

	startTimer();
	
	stopTimer();
	
	std::copy(sorted, sorted+size, arr);
	return arr;
}
