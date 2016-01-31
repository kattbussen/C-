CPP_FLAGS := -Wall -Werror

all: compareSort.cpp  
	@${MAKE} -s -C insertionSort lib
	@${MAKE} -s -C quickSort lib
	@${MAKE} -s -C selectionSort lib
	@mkdir -p lib
	@cp */lib/* lib/
	@g++ $(CPP_FLAGS) *.cpp -o compareSort -lInsSort -lQuickSort -lSelSort -L${PWD}/lib
	@echo "Build successful."

run: all
	@./compareSort

clean:
	@${MAKE} -s -C insertionSort clean
	@${MAKE} -s -C quickSort clean
	@${MAKE} -s -C selectionSort clean
	@rm -rf lib
	@rm -f *.o
	@rm -f compareSort
	@echo "Clean successful."
