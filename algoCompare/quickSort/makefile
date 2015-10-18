CPP_FLAGS := -std=c++11 -Wall

all: *.cpp *.h
	@g++ $(CPP_FLAGS) -c *.cpp
	@echo "Build successful."

lib: *.cpp *.h
	@mkdir -p lib
	@g++ $(CPP_FLAGS) -fPIC -c *.cpp
	@g++ -shared -o lib/libQuickSort.so *.o
	@echo "libQuickSort build successful."

clean:
	@rm -f *.o
	@rm -rf lib
	@echo "QuickSort clean successful."
