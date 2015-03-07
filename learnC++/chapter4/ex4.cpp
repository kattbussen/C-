#include <iostream>

int main()
{
	for(int i = 33; i < 127; i++)
	{
		std::cout << i << " and converted character " << static_cast<char>(i) << std::endl;
	}
}
