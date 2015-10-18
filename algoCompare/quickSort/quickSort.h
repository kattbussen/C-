#include <limits.h>
#include <chrono>
#include <algorithm>

#ifndef ABS_ALG
#define ABS_ALG
#include "include/AbstractAlgorithm.h"
#endif

class QuickSort : public SortAlgorithm
{
	public:
		int* sort(int arr[], int size);

	private:
		void quickRecurse(int arr[], int to, int from);
};
