#include <iostream>

int main()
{
	char str[] = "a short string";
	std::string stri = "a short string";

	std::cout << sizeof(str) << " " << sizeof(stri) << std::endl;
}

