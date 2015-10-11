#include <iostream>
#include "insertionSort/insertionSort.h"
#include "quicksort/quicksort.h"
#include "selectionSort/selectionSort.h"

int main()
{
	std::cout << "compare." << std::endl;
	insertionSort();
	quickSort();
	selectionSort();
}
