#include <iostream>

int main()
{
	typedef unsigned char uchar;

	typedef const unsigned char cuchar;
	
	typedef int* intP;
	
	typedef char** charPP;	

	typedef *char CharP;

	char a[3] = "ab";
	CharP ptr;
	CharP = &a;
	std::cout << *ptr << std::endl;

	typedef int* [7] Int7Ptr;

	typedef int**[7] Int7pp;

	typedef int[*int[8]] bla;
}
