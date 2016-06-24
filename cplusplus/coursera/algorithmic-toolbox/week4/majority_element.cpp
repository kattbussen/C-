#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int myFunc(vector<int> &a) {
	int size = a.size() / 2;
	for(int i = 0; i <= a.size() - size; i++) {
		if(a[i] == a[i+size]) {
			return 1;
		}
	}
	return 0;
}

bool sortFunc(int a, int b) {
	return a < b;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
	std::sort(a.begin(), a.end(), sortFunc);

	std::cout << myFunc(a) << std::endl;
}
