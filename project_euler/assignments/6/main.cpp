#include <stdio.h>
#include <iostream>

int main()
{
	long squares = 0;
	long sum = 0;

	for(int i = 0; i < 101; i++)
	{
		squares = squares + i*i;
		sum = sum + i;
	}

	sum = sum*sum;
	
  std::printf("Result is %li.\n", sum-squares);
}

