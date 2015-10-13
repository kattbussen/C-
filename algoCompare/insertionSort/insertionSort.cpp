#include "insertionSort.h"

std::chrono::high_resolution_clock::time_point start;
std::chrono::high_resolution_clock::time_point stop;
		
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
		
std::chrono::duration<double> InsertionSort::getTime()
{
	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>> (stop - start);
	return time_span;
}

void InsertionSort::startTimer()
{
	start = std::chrono::high_resolution_clock::now();
}
	
void InsertionSort::stopTimer()
{
	stop = std::chrono::high_resolution_clock::now();
}
