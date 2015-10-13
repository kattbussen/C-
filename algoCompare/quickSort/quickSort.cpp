#include "quickSort.h"

std::chrono::high_resolution_clock::time_point start;
std::chrono::high_resolution_clock::time_point stop;
		
int* QuickSort::sort(int arr[], int size)
{
	int sorted[size];

	startTimer();
	
	stopTimer();
	
	std::copy(sorted, sorted+size, arr);
	return arr;
}
		
std::chrono::duration<double> QuickSort::getTime()
{
	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>> (stop - start);
	return time_span;
}

void QuickSort::startTimer()
{
	start = std::chrono::high_resolution_clock::now();
}
	
void QuickSort::stopTimer()
{
	stop = std::chrono::high_resolution_clock::now();
}
