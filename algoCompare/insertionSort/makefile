all: *.cpp *.h
	@g++ -std=c++11 -c *.cpp
	@echo "Build successful."

lib: *.cpp *.h
	@mkdir -p lib
	@g++ -std=c++11 -Wall -fPIC -c *.cpp
	@g++ -shared -o lib/libInsSort.so *.o
	@echo "libInsSort build successful."

clean:
	@rm -f *.o
	@rm -rf lib
	@echo "InsertionSort clean successful."
