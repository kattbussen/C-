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

long long lcm(int a, int b) {
  int greatest = gcd(a,b);
	long long mult = a*b;
	return (long long)(a / greatest) * b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
