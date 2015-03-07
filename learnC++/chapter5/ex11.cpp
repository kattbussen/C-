#include <iostream>
#include <vector>

using namespace std;

bool contains(vector<string> list, string string)
{
	vector<std::string>::const_iterator it;
	for(it = list.begin(); it < list.end(); ++it)
	//for(auto i : list)
	{
		if( *it == string)
			return true;
	}
	return false;
}

int main()
{
	string input = "";
	vector<string> items;	
	
	while (input != "quit")
	{
		cin >> input;

		if(!contains(items, input))
			items.push_back(input);
	}

	cout << "you entered the following words: " << endl;
	for(auto i : items)
	{
		cout << i << endl;
	}
}
