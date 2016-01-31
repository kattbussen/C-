#include <iostream>

int main()
{
	int primes [2000000] = {};
	long sum = 0;

	primes[0] = 0;
	primes[1] = 0;
	primes[2] = 2;

	for(int i = 3; i < 2000000; i++)
	{
		if(i%2 != 0)	
			primes[i] = i;
		else
			primes[i] = 0;
	}

	for(int i = 3; i < 2000000; i++)
	{
		int number = 2;

		if(primes[i] != 0)
		{
			while(number*i < 2000000)
			{
				primes[number*i] = 0;
				number++;	
			}
		}
	}

	for(int i = 0; i < 2000000; i++)
	{
		sum+=primes[i];
	}

  std::cout << "Result is " << sum << "." << std::endl;
}

