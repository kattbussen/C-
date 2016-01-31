#include <iostream>
#include <math.h>

int main()
{
	long incNumber = 0;
	long number = 0;
	long divNumber = 1;
	int divisors = 0;
	
	while(divisors <= 500)
	{
		incNumber++;
		number = number + incNumber;
		divisors = 0;		

		for(divNumber = 1; divNumber <= sqrt(number); divNumber++)
		{
			if(number%divNumber == 0)
				divisors+=2;	
		}
	}

	std::cout << "Answer is " << number << "." << std::endl;
}

