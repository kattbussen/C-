#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size()-1; 
 
	int index = -1;
	int size = a.size();	
	bool iterate = true;
	int itIndex = size/2;

	while(iterate) {
		if(a[itIndex] == x) {
			index = itIndex;
			iterate = false;
		}
		else if(a[itIndex+1] == x)
		{
			index = itIndex+1;
			iterate = false;
		}
		else if(itIndex == left || itIndex == right) {
			iterate = false;
		}
		else if(a[itIndex] > x) {
			right = itIndex;
			itIndex = itIndex / 2;
		}	
		else if(a[itIndex] < x) {
			left = itIndex;
			itIndex = itIndex + (right - left) / 2;
		}
	}
	
 
	return index;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cout << binary_search(a, b[i]) << ' ';
  }
	std::cout << std::endl;
}
