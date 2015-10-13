all: *.cpp *.h
	@g++ -std=c++11 -c *.cpp
	@echo "Build successful."

lib: *.cpp *.h
	@mkdir -p lib
	@g++ -std=c++11 -Wall -fPIC -c *.cpp
	@g++ -shared -o lib/libQuickSort.so *.o
	@echo "libQuickSort build successful."

clean:
	@rm -f *.o
	@rm -rf lib
	@echo "QuickSort clean successful."
