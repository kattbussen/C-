#include <iostream>
#include <string>
#include <algorithm>

void reverse(const char* &str)
{
	std::string ny(str);	
	std::reverse(ny.begin(), ny.end());
	ny+='\0';

	str = ny.c_str();
}

void reverse2(const char* &str)
{
	const char* tmp = str;
	while(*tmp != '\0')
	{
		tmp++;
	}

	
}

int main()
{
	const char * str = "blabla";
	
	//std::string tmp(str);
	//std::reverse(tmp.begin(), tmp.end());
	//str = tmp.c_str();
	
	std::cout << str << std::endl;
	
	reverse(str);
	std::cout << str << std::endl;
	//reverse2(str);
	//std::cout << str << std::endl;
}
