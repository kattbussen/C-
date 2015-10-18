#include "quickSort.h"

/************************************************
*
* The private recursive function for quickSort. 
*
************************************************/
void QuickSort::quickRecurse(int arr[], int from, int to)
{
	int pivot = arr[(from + to) / 2];
	int left = from;
	int right = to;
	
	while(left <= right)
	{
		while(arr[left] < pivot)
			left++;
		
		while(arr[right] > pivot)
			right--;
		
		if(left <= right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
	}
	
	if(from < right)
		quickRecurse(arr, from, right);

	if(left < to)
		quickRecurse(arr, left, to);
}

/************************************************
*
* Implements quickSort and measures the time
* it takes to sort the given array of integers.
*
************************************************/
int* QuickSort::sort(int arr[], int size)
{
	startTimer();
	quickRecurse(arr, 0, size-1);	
	stopTimer();
	
	return arr;
}
