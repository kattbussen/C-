all: rbtree.cpp main.cpp
	@clang++ -std=c++11 -o out rbtree.cpp main.cpp

.PHONY: clean

clean:
	@rm -f out
	@rm -f outTest
	@echo "clean done."

test: rbtree.cpp rbtreeTest.cpp
	@clang++ -std=c++11 -o outTest rbtree.cpp rbtreeTest.cpp

