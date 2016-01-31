#include <stdio.h>
#include <iostream>

int main()
{
	
	int resultInt = 0;
	std::string resultString = "";
	std::string reverseString = "";

	for(int i = 0; i < 1000; i++)
	{
		for(int j = i; j < 1000; j++)
		{
			int result = i*j;
			if(result > resultInt)
			{
				resultString = std::to_string(result);
				reverseString = std::string(resultString.rbegin(), resultString.rend());

				if(resultString.compare(reverseString) == 0)
				{
					resultInt = result;
				}
			}
		}
	}	
  std::printf("Result is %i.\n", resultInt);
}

