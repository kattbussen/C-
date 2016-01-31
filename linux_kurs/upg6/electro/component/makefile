all: lib libtest.c
	@cp -f libcomponent.so ../lib/libcomponent.so
	@rm -f libcomponent.so
	@gcc libtest.c -o component_test -lcomponent -L${PWD}/lib

lib:	libcomponent.so
	@cp libcomponent.so ../lib

libcomponent.so: component.c component.h
	@gcc -fPIC -c component.c
	@gcc -shared -o libcomponent.so component.o

clean:
	@rm -rf lib
	@rm -f component.o
	@rm -f ../lib/libcomponent.so
	@rm -f component_test
