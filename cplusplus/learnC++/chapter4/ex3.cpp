#include <iostream>

enum Letters {a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z};
enum Test {Hej, detta, ar, ett, test};

int main()
{
	std::cout << "short: " << sizeof(short) << std::endl;
	std::cout << "int: " << sizeof(int) << std::endl;
	std::cout << "double: " << sizeof(double) << std::endl;
	std::cout << "string: " << sizeof(std::string) << std::endl;
	std::cout << "long: " << sizeof(long) << std::endl;
	std::cout << "bool: " << sizeof(bool) << std::endl;
	std::cout << "char: " << sizeof(char) << std::endl;
	std::cout << "enum: " << sizeof(Letters) << std::endl;
	std::cout << "enum2: " << sizeof(Test) << std::endl;
}
