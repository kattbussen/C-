#include <iostream>

int main()
{
	long calls = 0;
	long mostCalls = 0;
	long longestChainNumber = 0;
	long incNumber = 1;
	long number = incNumber;

	while(incNumber < 1000000)
	{
		number = incNumber;

		while(number != 1)
		{
			calls++;
			if(number%2 == 0)
			{
				number = number/2;
			}
			else
			{
				number = 3 * number +1;
			}
		}

		if(calls > mostCalls)
		{	
			longestChainNumber = incNumber;
			mostCalls = calls;
		}
	
		incNumber++;
		calls = 0;
	}
	
  std::cout << "Longest chain is " << mostCalls << " for number " << longestChainNumber << std::endl;
}

