CPPFLAGS := -std=c++11 -Wall

all: 
	@${MAKE} -s -C ../insertionSort lib
	@${MAKE} -s -C ../quickSort lib
	@${MAKE} -s -C ../selectionSort lib
	@mkdir -p lib
	@cp -f ../insertionSort/lib/* lib/
	@cp -f ../quickSort/lib/* lib/
	@cp -f ../selectionSort/lib/* lib/
	@g++ $(CPP_FLAGS) testSort.cpp -o runSortTest -lInsSort -lQuickSort -lSelSort -L${PWD}/lib
	@echo "Build successful."

run: all
	@./runSortTest
	
clean:
	@${MAKE} -s -C ../insertionSort clean
	@${MAKE} -s -C ../quickSort clean
	@${MAKE} -s -C ../selectionSort clean
	@rm -f runSortTest
	@rm -rf lib
	@echo "Clean successful."
