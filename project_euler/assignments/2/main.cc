#include <stdio.h>
#include <iostream>

int main()
{
  long result = 2;

	long first = 2;
	long second = 1;

	while((first+second) < 4000000)
	{
		long fibo = first+second;

		if(fibo%2 == 0)
			result+=fibo;

		second = first;
		first = fibo;

		std::printf("value is %li. \n", fibo);
	}

	std::printf("Result is: %li.\n", result);
}

