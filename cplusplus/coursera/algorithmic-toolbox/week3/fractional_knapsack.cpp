#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Tuple {
	public:
		int val, weight;
		Tuple(int val_, int weight_) {
			val = val_;
			weight = weight_;
		}
};

bool sortFunc(Tuple *first, Tuple *second) {
	double ratio1;
	double ratio2;
	
	ratio1 = double(first->val) / double(first->weight);
	ratio2 = double(second->val) / double(second->weight);

	return (ratio1 > ratio2);
}

int main() {
  int n;
  int capacity;
	double value = 0.0;
  std::cin >> n >> capacity;
	vector<Tuple*> vec;
	int first, second;
  
	for (int i = 0; i < n; i++) {
  	std::cin >> first >> second;
		Tuple *tup = new Tuple(first, second);
		vec.push_back(tup);
	}

	std::sort(vec.begin(), vec.end(), sortFunc);	
	vector<Tuple*>::iterator it = vec.begin();

	while(capacity > 0 && it != vec.end()) {
		Tuple *tmp = *it;
		if(tmp->weight < capacity) {
			value += tmp->val;	
			capacity -= tmp->weight;
		}
		else {
			value += double(capacity) * double(tmp->val) / double(tmp->weight);
			capacity = 0;	
		}
		++it;	
	}
	
  std::cout.precision(10);
  std::cout << value << std::endl;
  return 0;
}
