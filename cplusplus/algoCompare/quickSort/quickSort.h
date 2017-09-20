#include <limits.h>
#include <algorithm>

#ifndef ABS_ALG
#define ABS_ALG
#include "include/abstractAlgorithm.h"
#endif

class QuickSort : public SortAlgorithm
{
	public:
		void sort(int arr[], int size);

	private:
		void quickRecurse(int arr[], int to, int from);
};
