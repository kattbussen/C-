#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
  int noElements = numbers.size();
	int index1 = -1;
	int index2 = -1;

	for(int i = 0; i < noElements; i++) {
		if(index1 == -1 || numbers[i] > numbers[index1]) {
			index1 = i;
		}
	}

	for(int i = 0; i < noElements; i++) {
		if(i != index1 && (index2 == -1 || numbers[i] > numbers[index2])) {
			index2 = i;
		}
	}
	
	return (long long)numbers[index1] * numbers[index2];
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
