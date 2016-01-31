#include <iostream>
#include <math.h>

int main()
{
	std::string number = std::to_string(pow(2, 1000));

	const char* p_c_str = number.c_str();

	int result = 0;

	while(*p_c_str != '.')
	{
		result += (*p_c_str - '0');
		p_c_str++;
	}

	std::cout << "Result is " << result << "." << std::endl;
}

