#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "component.h"

float e_series[12] = {1, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2};

//Calculates what three resistances from the E12 series that is a good approximation of orig_resistance.
int e_resistance(float orig_resistance, float *res_array)
{
	int scale = 1;
	float tmpRes = orig_resistance;
	int arrayIndex = 0;	

	if(!res_array)
	{
		printf("Function e_resistance received a null pointer. Exiting.\n");
		return -1;
	}

	res_array[0] = 0;
	res_array[1] = 0;
	res_array[2] = 0;


	while(tmpRes > 0)
	{
		int i = 0;

		for(i = 0; i < 12; i++)
		{
			//If tmpRes are not larger than zero we are done.
			if(tmpRes > 0)
			{
				if(tmpRes == (e_series[i] *scale))
				{
					tmpRes = tmpRes - e_series[i] * scale;
					res_array[arrayIndex] = e_series[i] * scale;
					arrayIndex++;
					scale = 1;
					i = 0;
				}
				else if(i != 0 && tmpRes < (e_series[i] * scale) && arrayIndex < 2)
				{
					tmpRes = tmpRes - e_series[i-1] * scale;
					res_array[arrayIndex] = e_series[i-1] * scale;
					arrayIndex++;
					scale = 1;
					i = 0;
				}
				else if(tmpRes < (e_series[i] * scale) && arrayIndex < 2)
				{
					tmpRes = tmpRes - e_series[11] * scale / 10;
					res_array[arrayIndex] = e_series[11] * scale / 10;
					arrayIndex++;
					scale = 1;
					i = 0;
				}
				else if(tmpRes < (e_series[i] * scale))
				{
					tmpRes = 0;
					res_array[arrayIndex] = e_series[i] * scale;
					arrayIndex++;
					scale = 1;
					i = 0;
				}	
			}	
		}
		//If no matches are found, we need a higher resistance.
		scale = scale * 10;
	}

	return arrayIndex;
}
