#include <iostream>
#include <string>
#include <set>
#include <algorithm>

bool permutation(std::string first, std::string second)
{
	std::set<char> fSet;
	std::set<char> sSet;
	std::set<char>::iterator it;

	for(char f : first)
	{
		if(fSet.find(f) == fSet.end())
		{
			fSet.insert(f);	
		}
		else
		{
			fSet.erase(f);
		}	
	}	

	for(char s : second)
	{
		if(sSet.find(s) == sSet.end())
		{
			sSet.insert(s);
		}
		else
		{
			sSet.erase(s);
		}
	}
	
	return fSet == sSet;
}

bool permut(std::string first, std::string second)
{	
	std::sort(first.begin(), first.end());
	std::sort(second.begin(), second.end());

	return first == second;
}	

int main()
{
	std::string first = "ejh";
	std::string second = "ejh";
	
	bool answer = permutation(first, second);
	std::cout << answer << std::endl;
	answer = permut(first, second);
	std::cout << answer << std::endl;
}
