#include <stdio.h>
#include <stdlib.h>
#include "component.h"

int main(int argc, char *argcv[])
{
	float buff[3];
	buff[0] = 0;
	buff[1] = 1;
	buff[2] = 2;
	
	float res = 1002.0;
	
	int bla = e_resistance(res, buff);
	printf("%f %f %f\n", buff[0], buff[1], buff[2]);

	return 0;
}
