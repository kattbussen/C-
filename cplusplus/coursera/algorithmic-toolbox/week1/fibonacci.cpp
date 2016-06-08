#include <iostream>

long long calc_fib(int n) {
	int count = 1;
	long long previous = 1;
	long long befPrevious = 0;
	long long current = 0;

	while(count < n) {
		current = previous + befPrevious;
		befPrevious = previous;
		previous = current;
		count++;
	}
    
	return current;
}

int main() {
	int n = 0;
  std::cin >> n;

	if(n == 0)
		std::cout << 0 << std::endl;
	else if(n == 1)
		std::cout << 1 << std::endl;
	else
			std::cout << calc_fib(n) << '\n';
    
		return 0;
}
