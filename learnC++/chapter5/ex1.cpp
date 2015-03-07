#include <string>

int main()
{
	char character = 'a';
	char *charPi = &character;

	int intArr[10] = {};

	int (&intArrRef)[10] = intArr;	

	std::string stringArr[5];
	std::string *stringArrP = stringArr;

	char* *charPP = &charPi;;

	const int cInt = 0;

	const int *constIntP = &cInt;

	const int *const ccIntP = &cInt;
}
