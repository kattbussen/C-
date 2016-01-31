#include <iostream>

void f(char cha)
{
}

void g(char& cha)
{

}

void h(const char& cha)
{

}

int main()
{
	char cha = 'a';
	int first = 49;
	unsigned char uc = 'b';
	signed char sc = 'c';	

	f(cha);
	f(first);
	f(uc);
	f(sc);

	g(cha);
	//g(first);
	//g(uc);
	//g(sc);

	h(cha);
	h(first);
	h(uc);
	h(sc);
}
