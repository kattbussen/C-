#include <iostream>

int gcd(int a, int b) {
	int first = a;
	int second = b;
	int remainder = -1; 
	
	while(remainder != 0) {
		remainder = first % second; 
		first = second;
		second = remainder;
	}
		
	return first;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
