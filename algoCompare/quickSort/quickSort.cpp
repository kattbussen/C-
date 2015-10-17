#ifndef qSort_H
#define qSort_H
#include "quickSort.h"
#endif

int* QuickSort::sort(int arr[], int size)
{
	int sorted[size];

	startTimer();
	
	stopTimer();
	
	std::copy(sorted, sorted+size, arr);
	return arr;
}
