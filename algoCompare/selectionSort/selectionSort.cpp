#ifndef sSort_H
#define sSort_H
#include "selectionSort.h"
#endif

int* SelectionSort::sort(int arr[], int size)
{
	int sorted[size];

	startTimer();
	
	stopTimer();
	
	std::copy(sorted, sorted+size, arr);
	return arr;
}
