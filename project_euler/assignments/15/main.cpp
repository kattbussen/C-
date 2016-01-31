#include <iostream>

int tableSize = 21;
long table[21][21] = {};

void print()
{
	for(int i = 0; i < tableSize; i++)
	{
		for(int j = 0; j < tableSize; j++)
		{
			std::cout << table[i][j] << " "; 
		}
		std::cout << std::endl;
	}
}

int main()
{
	for(int i = 0; i < tableSize; i++)
	{
		table[tableSize-1][i] = 1;
		table[i][tableSize-1] = 1;
	}

	print();
	std::cout << std::endl;

	for(int i = tableSize - 2; i >= 0; i--)
	{
		for(int j = tableSize - 2; j >= 0; j--)
		{
			table[i][j] = table[i+1][j] + table[i][j+1];
		}
	}	

	print();
	std::cout << std::endl;

	std::cout << table[0][0] << std::endl;
	/*long bla = 1;
	for(int i = 0; i < 20; i++)
	{
		bla *= (2 * 20) - i;
		bla /= i + 1;
	}
	std::cout << bla << std::endl;*/
}

