CC = gcc

all:	lib

lib:	power.o 
	$(CC) -shared -fPIC -o libpower.so power.o 
	cp -f libpower.so ../lib/libpower.so
	rm -f libpower.so

power.o: power.c power.h
	$(CC) -c -fPIC power.c

clean:
	rm ../lib/libpower.so
	rm ./power.o
