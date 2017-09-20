#include <iostream>
#include "insertionSort/insertionSort.h"
#include "quickSort/quickSort.h"
#include "selectionSort/selectionSort.h"

/****************************************
*
* Fills an array of size with random
* values between 1 and 100;
*
****************************************/
void randArray(int arr[], int size)
{
	for(int i = 0; i < size; i++)
		arr[i] = rand() % 100 + 1;
}

/****************************************
*
* Prints the time it takes for the different
* algorithms to sort an array.
*
****************************************/
void compareAlgs()
{
	int size = 10000;
	int arr[size];

	randArray(arr, size);	
	InsertionSort inSort;
	inSort.sort(arr, size);
	std::cout << "InsertionSort with " << size << " elements took " << inSort.getTime().count() << " sec." << std::endl;
	
	randArray(arr, size);	
	SelectionSort selSort;
	selSort.sort(arr, size);
	std::cout << "SelectionSort with " << size << " elements took " << selSort.getTime().count() << " sec." << std::endl;
	
	randArray(arr, size);
	QuickSort qSort;
	qSort.sort(arr, size);
	std::cout << "QuickSort with " << size << " elements took " << qSort.getTime().count() << " sec." << std::endl;
}

int main()
{
	compareAlgs();
}
