# This makefile is used to verify that the two
# functions included into the shared library libpower
# can be accessed at link time by another program.

CC = gcc
LIBFLAG= -L../../lib -lpower
TSTDIR= ./

all:	test_power

test_power:	$(TSTDIR)test_power.o
		$(CC)  -Wall -ansi -o test_power $(TSTDIR)test_power.o $(LIBFLAG)

test_power.o:	$(TSTDIR)test_power.c 
		$(CC)  -Wall -ansi -c $(TSTDIR)test_power.c 
