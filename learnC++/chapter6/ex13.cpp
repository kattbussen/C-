#include <iostream>

char* cat(char first[], char second[])
{
	int totalSize = std::strlen(first) + std::strlen(second);
	char *concat = new char[totalSize];
	char *start = concat;	
	char *fp = &first[0];
	char *sp = &second[0];	
	
	while(*fp != '\0')
	{
		*concat = *fp;
		fp++;
		concat++;
	}
	while(*sp != '\0')
	{
		*concat = *sp;
		sp++;
		concat++;
	}
	*concat = '\0';

	return start;
}

int main()
{
	char a[] = "stor";
	char b[] = "apa";
	char *res = cat(a,b);
	std::cout << res << std::endl;
	delete res;
}
