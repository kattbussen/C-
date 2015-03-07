#include <iostream>

void print(std::string (&str)[4])
{
	int size = sizeof(str) / sizeof(str[0]);
	
	std::cout << "size is " << size << std::endl;

	for(int i = 0; i < size; i++)
	{
		std::cout << str[i] << std::endl;
	}
}

int main()
{
	std::string strings[] = {"1", "2", "3", "4"};

	int size = sizeof(strings) / sizeof(strings[0]);

	for(int i = 0; i < size; i++)
	{
		std::cout << strings[i] << std::endl;
	}
	
	print(strings);
}
