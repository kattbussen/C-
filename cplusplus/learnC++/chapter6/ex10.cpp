#include <iostream>

int strlen(char str[])
{
	int length = 0;
	char *point = &str[0];

	while(*point != '\0')
	{
		length++;
		point++;
	}
	
	return length;
}

bool strcpy(char str[], char copy[])
{
	char *source = &str[0];
	char *destination = &copy[0];

	while(*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}

	return true;
}

bool strcmp(char strOne[], char strTwo[])
{
	char *fPoint = &strOne[0];
	char *sPoint = &strTwo[0];

	while(*fPoint == *sPoint)
	{
		fPoint++;
		sPoint++;

		if(*fPoint == '\0' && *sPoint == '\0')
			return true;
	}

	return false;
}

int main()
{
	char theThing[] = "apa";
	char theCopy[] = "apa";
	char theAlmostCopy[] = "apaa";
	int length = strlen(theThing);
	std::cout << length << " " << std::strlen(theThing) << std::endl;

	bool first = strcmp(theThing, theCopy);
	bool second = strcmp(theThing, theAlmostCopy);

	std::cout << first << " " << second << std::endl;

	char copy[4] = {};
	strcpy(theThing, copy);
	std::cout << copy << std::endl;
}
