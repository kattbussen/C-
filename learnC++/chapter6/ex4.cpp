#include <iostream>

using namespace std;

int main()
{
	unsigned int zero = 0;
	int i = 1;
	int j = 3;
	cout << i << endl;
	//i << 1;
	cout << (i<<2) << endl;
	cout << (i&j) << endl;
	cout << (i|j) << endl;
	cout << (~zero) << endl;
}
