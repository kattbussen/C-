#include <iostream>
#include <string>

std::string compress(std::string str)
{
	std::sort(str.begin(), str.end());
	
	std::string ny = "";
	int count = 0;
	char prev = str[0];

	for(char c : str)
	{
		if(c == prev)
		{
			count++;
		}
		else
		{
			ny+=prev;
			ny = ny + std::to_string(count);
			count = 1;
		}
		prev = c;
	} 
	ny+=prev;
	ny = ny + std::to_string(count);

	return ny;
}

int main()
{
	std::string str = "hejsan";
	std::string ny = compress(str);

	if(ny.size() < str.size())
		str = ny;

	std::cout << str << std::endl;
}
