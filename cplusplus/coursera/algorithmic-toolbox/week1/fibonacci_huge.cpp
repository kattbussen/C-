#include <iostream>

long long calc_fib2(long long n, long long m) {
  int count = 1;
  long long previous = 1;
  long long befPrevious = 0;
  long long current = 0;
	
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;

  while(count < n) {
    current = (previous + befPrevious) % m;
    befPrevious = previous;
    previous = current;
    count++;
  }
    
  return current;
}

long long get_fibonaccihuge(long long n, long long m) {
	int period = 0;
	int fib = 2;
	long long first = -1;
	long long second = 1;

	int prev = 1;
	int prevprev = 0;
	int tmp = 0;

	while( (first != 0 || second != 1) && (period < n) ) {
		first = second;

		tmp = (prev + prevprev) % m;
		prevprev = prev;
		prev = tmp;

		second = tmp;

		period++;
		fib++;
	}		  

	long long result = 0;
	long long real = 0;
	
	if(period != n) {
		result = n % period;	
		real = calc_fib2(result, m);
	}
	else {
		result = n;
		real = calc_fib2(n, m);
	}

	return real;
}

int main() {
    long long n, m;
    std::cin >> n >> m;

		if(n == 0) 
			std::cout << 0 << std::endl;
		else if(n == 1)
			std::cout << 1 << std::endl;
		else {
    	std::cout << get_fibonaccihuge(n, m) << std::endl;
		}
}
