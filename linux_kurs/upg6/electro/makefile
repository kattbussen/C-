# This makefile is used to build the libraries:
#	- libpower        [source held in ./power]
#	- libresistance   [source held in ./resistance]
#	- libcomponent    [source held in ./component]

# The above mentioned libraries are installed in $(INSTLIB) and the
# related header files in $(INSTINC).

# In order to perform the installation do:
#        sudo make install

CC=gcc
INSTLIB=/usr/local/lib
INSTINC=/usr/local/include
INCLOCAL=-I./power -I./resistance -I./component

all:	lib electrotest  
	$(MAKE) -C resistance all
	$(MAKE) -C power all
	$(MAKE) -C component all
clean: 
	$(MAKE) -C resistance clean
	$(MAKE) -C power clean
	$(MAKE) -C component clean


.PHONY:	lib
lib:
	$(MAKE) -C resistance lib
	$(MAKE) -C power lib
	$(MAKE) -C component lib

electrotest:	electrotest.o
		$(CC) -L./lib -Wl,-rpath=./lib -Wall -o electrotest electrotest.o -lpower -lresistance -lcomponent

electrotest.o:	electrotest.c 
		$(CC) $(INCLOCAL) -Wall -ansi -c electrotest.c

install:	all
		cp lib/*.so $(INSTLIB)
		cp power/power.h   $(INSTINC)
		cp resistance/libresistance.h  $(INSTINC)
		cp component/component.h   $(INSTINC)
		chmod 755 $(INSTLIB)/libpower.so
		chmod 755 $(INSTLIB)/libcomponent.so
		chmod 755 $(INSTLIB)/libresistance.so
		ldconfig
		rm -f electrotest
#               Let's test that we can use the libraries when they are installed
#               in their final destination.
		gcc -o electrotest electrotest.c -lpower -lresistance -lcomponent 




