#include <iostream>

using namespace std;

int matches = 0;
int cmatches = 0;

void theFunction(string *name, string *search)
{	
	string::iterator it;
	
	for(it = (*name).begin(); it != (*name).end(); it++)
	{
		if((*search)[0] == (*it) && (*search)[1] == (char)(*(it+1)))
		{
			matches++;
			cout << "found a match." << endl;
		}
	}
}

void cTheFunction(char *name, char *search)
{
	while(*name != '\0')
	{
		if(*name == *search && *(name+1) == *(search+1))
		{
			cout << "found a cmatch." << endl;
			cmatches++;
		}
		name++;
	}
}

int main()
{
	string name = "abaacaadaa";
	string search = "aa";
	theFunction(&name, &search);
	cout << "Found " << matches << " matches." << endl;

	char cname[] = "abaacaadaa";
	char csearch[] = "aa";
	cTheFunction(cname, csearch);
	cout << "Found " << cmatches << " cmatches." << endl;
}
