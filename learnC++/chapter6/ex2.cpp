#include <iostream>
#include <map>

using namespace std;

void read(multimap<string, double> &storage)
{
	cout << "enter values, use 'quit' to quit." << endl;
	string name = "";
	double value = 0;

	while(name != "quit")
	{
		cout << "enter name: " << endl;
		getline(cin, name);
		
		if(name != "quit")
		{
			cout << "enter value: " << endl;
			cin >> value;
			cin.ignore();
			
			storage.insert(pair<string, double>(name, value));
		}
	}
}

int main()
{
	multimap<string, double> storage;
	string prevName = "";
	double sum = 0;
	double count = 0;

	read(storage);
	cout << storage.size() << " entries added." << endl;

	multimap<string, double>::iterator it = storage.begin();
	
	while(it != storage.end())
	{
		cout << "handling " << it->first << endl;
		if(prevName != it->first && count != 0)
		{	
			cout << prevName << ", sum: " << sum << " and average: " << sum/count << endl;
			prevName = it->first;
			sum = it->second;
			count = 1;
		}	
		else if(sum == 0 && count == 0)
		{
			prevName = it->first;
			sum = it->second;
			count = 1;
		}
		else
		{
			sum = sum + it->second;
			count++;
		}
		it++;	
	}
	cout << prevName << ", sum: " << sum << " and average: " << sum/count << endl;
}

