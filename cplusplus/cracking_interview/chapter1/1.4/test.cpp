#include <iostream>
#include <string>

std::string func(std::string str, int leng)
{

	for(int i = 0; i < leng; i++)
	{
		if(str[i] == ' ')
		{
			str.replace(i, 1, "%20");	
		}
	}

	return str;
}


int main()
{
	std::string str = "bla bla  ";
	int leng = str.size();

	std::cout << str.size() << std::endl;
	str = func(str, leng);
	std::cout << str << " " << str.size() << std::endl;
}
