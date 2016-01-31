#include <iostream>
#include <string>

bool substring(std::string first, std::string second)
{
	std::string::iterator fit;
	std::string::iterator sit;

	for(fit = first.begin(); fit != first.end(); fit++)
	{
		for(sit = second.begin(); sit != second.end(); sit++)
		{
			if(*fit == *sit)
			{
				std::string newString = std::string(sit, second.end()) + std::string(second.begin(), sit);
				std::cout << "built " << newString << std::endl;
				if(newString == first)
					return true;	
			}
		}
	}
	
	return false;
}

int main()
{
	std::string first = "halal";
	std::string second = "alhal";

	bool result = substring(first, second);
	std::cout << result << std::endl;
}
