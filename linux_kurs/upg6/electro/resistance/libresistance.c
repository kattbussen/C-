#include <stdio.h>
#include <stddef.h>
float calc_resistance(int count, char conn, float *array)
{
	float total = 0;
	int i = 0;
	if (array != NULL)
	{
		if(conn == 'P')
		{
			while (i < count)
			{
				if (array[i] == 0)
				{
					return 0;
				}
				else
				{
					total = total +(1/array[i]);
					i++;
				}
			}
			total = 1/total;
		}
		else if (conn == 'S')
		{
			while (i < count)
			{
				total = total + array[i];
				i++;
			}
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
	if (total != 0)
	{
		return total;
	}
}
