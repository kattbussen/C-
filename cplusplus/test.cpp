#include <iostream>

void reverse(char* ap)
{
	int size = sizeof(*ap);

	std::cout << ap << " " << size << std::endl;

}

int main()
{
	char array[] = "test";

	reverse(array);	


	std::cout << array << " " << sizeof(array) << std::endl;
}
