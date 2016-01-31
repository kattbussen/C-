
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
float calc_resistance();
void main()
{
	int count = 4;
	float array[4] = {10,14,54,16};
	char P = 'P';
	float calc = calc_resistance(count,P,array);
	printf("%f\n",calc);
}

