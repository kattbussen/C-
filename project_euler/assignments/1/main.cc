#include <stdio.h>
#include <iostream>

int main()
{
	int result = 0;

	for(int i = 0; i < 1000; i++)
	{
		if(i%3 == 0 || i%5 == 0)
			result+=i;
	}

	std::printf("result is: %i.", result);
}

