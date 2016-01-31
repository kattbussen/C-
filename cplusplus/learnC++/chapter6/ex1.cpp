#include <iostream>

using namespace std;

int main()
{
	int i = 0;
	char input_line[] = "hejsa?";
	int quest_count = 0;
	int max_length = 7;

	for(i = 0; i < max_length; i++)
	{
		if(input_line[i] == '?')
			quest_count++;
	}
	

	char *p = &input_line[0];

	while(*p != '\0')
	{
		if(*p == '?')
			quest_count++;

		p++;
	}

	cout << "Number of questionmarks: " << quest_count << endl;	
}
