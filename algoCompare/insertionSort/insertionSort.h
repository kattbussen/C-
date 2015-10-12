#include "include/AbstractAlgorithm.h"

class InsertionSort : SortAlgorithm
{
	public:
		int* sort(int[], int);
		float getTime();

	private:
		void startTimer();
		void stopTimer();
};
