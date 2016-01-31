#include <iostream>

int main()
{
	char a = 'a';
	char *pa = &a;
	int i = 0;

	(*pa)++;
  char &b = *(--pa);
	std::cout << b << std::endl;
	(++i)--;
}
