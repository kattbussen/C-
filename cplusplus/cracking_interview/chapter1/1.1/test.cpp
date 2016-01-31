#include <iostream>
#include <string>
#include <set>

int main()
{
	std::string s = "hejsan allihopa";
	std::set<char> set;
	bool allUnique = true;
	std::pair<std::set<char>::iterator, bool> retur;

	std::string::iterator it;
	
	for(it = s.begin(); it != s.end(); it++)
	{
		retur = set.insert(*it);
		allUnique = retur.second;
		if(!allUnique)
		{
			break;
		}
	}
	
	std::cout << allUnique << std::endl;
}
