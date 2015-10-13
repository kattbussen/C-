#include <limits.h>
#include <chrono>
#include <algorithm>
#include "include/AbstractAlgorithm.h"

class QuickSort : SortAlgorithm
{
	public:
		int* sort(int[], int);
		std::chrono::duration<double> getTime();

	private:
		void startTimer();
		void stopTimer();
};
