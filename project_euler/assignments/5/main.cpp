#include <stdio.h>
#include <iostream>

int main()
{
	long result = 0;
	long number = 2520;
	while(result == 0)
	{
		for(int divisor = 1; divisor < 21; divisor ++)
		{
			if(number%divisor != 0)
				break;

			if(divisor == 20)
			{
				result = number;
			}
		}
		number = number + 2;
	}
	
  std::printf("Result is %li.\n", result);
}

