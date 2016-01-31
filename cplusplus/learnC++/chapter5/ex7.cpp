#include <iostream>

struct teburu {
	std::string name;
	int days;
};

int main()
{
	std::string table[4][2] = 
	{
	{"Januari", "31"},
	{"Februari", "28"},
	{"Mars", "31"},
	{"April", "30"}
	};

	teburu stuff[4] = 
	{
	{"Januari", 31},
	{"Februari", 28},
	{"Mars", 31},
	{"April", 30}
	};

	std::cout << sizeof(table) << " " << sizeof(stuff) << std::endl;

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			std::cout << table[i][j] << " ";
		}	
		std::cout << std::endl;
	}

	for(int i = 0; i < 4; i++)
	{
		std::cout << stuff[i].name << " " << stuff[i].days << std::endl;	
	}	
}
