#include <limits.h>
#include <chrono>
#include <algorithm>

#ifndef ABS_ALG
#define ABS_ALG
#include "include/AbstractAlgorithm.h"
#endif

class SelectionSort : public SortAlgorithm
{
	public:
		int* sort(int arr[], int size);

	private:
};
