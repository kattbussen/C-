#include <iostream>
#include <limits.h>
#include <float.h>

int main()
{
	unsigned test = 0;	

	std::cout << "min/max char: " << CHAR_MIN << " " << CHAR_MAX << std::endl;
	std::cout << "min/max short: " << SHRT_MIN << " " << SHRT_MAX << std::endl;
	std::cout << "min/max int: " << INT_MIN << " " << INT_MAX << std::endl;
	std::cout << "min/max long: " << LONG_MIN << " " << LONG_MAX << std::endl;
	std::cout << "min/max float: " << FLT_MIN << " " << FLT_MAX << std::endl;
	std::cout << "min/max double: " << DBL_MIN << " " << DBL_MAX << std::endl;
	std::cout << "min/max long double: " << LDBL_MIN << " " << LDBL_MAX << std::endl;
	std::cout << "min/max unsigned: " << 0 << " " << UINT_MAX << std::endl;
}
