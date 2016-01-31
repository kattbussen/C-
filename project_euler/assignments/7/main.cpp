#include <stdio.h>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> primes;	
	primes.push_back(2);

	long number = 3;
	bool passed = true;

	while(primes.size() != 10001)
	{
		passed = true;		

		for(std::vector<int>::iterator it = primes.begin(); it != primes.end(); ++it)
		{
			if(number%(*it) == 0)
			{
				passed = false;
			}
		}

		if(passed)
		{
			primes.push_back(number);
		}

		number = number + 2;
	}

  std::printf("Result is %i.\n", primes.back());
}

