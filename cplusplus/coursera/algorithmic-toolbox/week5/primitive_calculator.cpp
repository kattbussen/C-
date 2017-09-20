#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
	std::vector<int> calcvec(n+1);
	int num = 4;

	if(n == 1) {
		sequence.push_back(1);
		return sequence; 
	}
	if(n == 2) {
		sequence.push_back(1);
		sequence.push_back(2);
		return sequence; 
	}
	if(n == 3) {
		sequence.push_back(1);
		sequence.push_back(2);
		return sequence; 
	}

	calcvec[0] = 0;
	calcvec[1] = 1;
	calcvec[2] = 2;
	calcvec[3] = 2;

	int minDiv3 = 0;
	int minDiv2 = 0;
	int minInc = 0;

  while (num <= n) {
    if(num % 3 == 0) {
      minDiv3 = calcvec[num / 3];
    } 
		else {
			minDiv3 = INT_MAX;
		}
		
		if(num % 2 == 0) {
			minDiv2 = calcvec[num / 2];
		}
		else {
    	minDiv2 = INT_MAX;
    } 

		minInc = calcvec[num-1];
		
		calcvec[num] = std::min(std::min(minDiv3, minDiv2), minInc) + 1;
		num++;
  }

	num--;

	while(num != 1) {
		sequence.push_back(num);
		if(num % 3 == 0) {
			minDiv3 = calcvec[num / 3];
		}	
		else {
			minDiv3 = INT_MAX;
		}

		if(num % 2 == 0) {
			minDiv2 = calcvec[num / 2];
		}
		else {
			minDiv2 = INT_MAX;
		}
		minInc = calcvec[num-1];

		if(minDiv3 < minDiv2 && minDiv3 < minInc) {
			num = num / 3;
		}
		else if(minDiv2 < minInc) {
			num = num / 2;
		}
		else {
			num = num-1;
		}
	}
	sequence.push_back(1);
 
	reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
	std::cout << std::endl;
}
