all: lib

libresistance.o: libresistance.c
	gcc -c -fPIC libresistance.c

lib: 	libresistance.o
	gcc -shared -fPIC -o libresistance.so libresistance.o
	cp -f libresistance.so ../lib/libresistance.so
	rm -f libresistance.so

clean:
	rm -f libresistance.o
	rm -f ../lib/libresistance.so

