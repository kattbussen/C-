VPATH = .:../insertionSort/

.PHONY: all

all: InsertionSort QuickSort SelectionSort testSort.cpp

InsertionSort: insertionSort.cpp insertionSort.h
	@g++ -std=c++11 -Wall testSort.cpp ../insertionSort/insertionSort.cpp -o runInsSortTest
	@echo "InsertionSort built successfully."

QuickSort:
	@echo "quicksort."

SelectionSort:
	@echo "selectionSort."

run: all
	@./runInsSortTest

clean:
	@rm -f runInsSortTest
	@echo "Clean successful."
