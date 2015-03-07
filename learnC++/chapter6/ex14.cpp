#include <iostream>

void rev(char str[])
{

	//str[0] = 'a';	
	char *start = &str[0];
	char *end = &str[0];
	
	while(*end != '\0')
		end++;

	end--;

	while(start != end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;

		start++;
		if(start != end)
			end--;
	}	
}

int main()
{
	char word[] = "reverse";
	rev(word);
	std::cout << word << std::endl;
}
