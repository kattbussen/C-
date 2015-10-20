CPP_FLAGS := -Wall -Werror

all: *.cpp *.h
	@g++ $(CPP_FLAGS) -c *.cpp
	@echo "Build successful."

lib: *.cpp *.h
	@mkdir -p lib
	@g++ $(CPP_FLAGS) -fPIC -c *.cpp
	@g++ -shared -o lib/libInsSort.so *.o
	@echo "libInsSort build successful."

clean:
	@rm -f *.o
	@rm -rf lib
	@echo "InsertionSort clean successful."
