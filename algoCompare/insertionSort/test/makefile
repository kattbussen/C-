VPATH = ../

all: testInsertionSort.cpp insertionSort.cpp insertionSort.h
	@g++ -std=c++11 -Wall testInsertionSort.cpp ../insertionSort.cpp -o runTest
	@echo "Build successful."

clean:
	@rm -f runTest
	@echo "Clean successful."
