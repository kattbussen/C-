all: compareSort.cpp  
	@${MAKE} -s -C insertionSort lib
	@${MAKE} -s -C quickSort lib
	@${MAKE} -s -C selectionSort lib
	@mkdir -p lib
	@cp */lib/* lib/
	@g++ -std=c++11 -Wall *.cpp -o compareSort -lInsSort -lQuickSort -lSelSort -L${PWD}/lib
	@echo "Build successful."

clean:
	@${MAKE} -s -C insertionSort clean
	@${MAKE} -s -C quickSort clean
	@${MAKE} -s -C selectionSort clean
	@rm -rf lib
	@rm -f *.o
	@rm -f compareSort
	@echo "Clean successful."
