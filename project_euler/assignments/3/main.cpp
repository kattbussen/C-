#include <stdio.h>
#include <iostream>
#include <vector>

int main()
{
	long number = 600851475143;

	std::vector<int> vec;

	int divider = 2;

	while(number > 1 || divider*divider > number)
	{
		while(number%divider == 0)
		{
			vec.push_back(divider);
			number = number/divider;
		}
		divider++;
	}
	
  std::printf("Result is %i.\n", vec.back());

	return 0;
}

