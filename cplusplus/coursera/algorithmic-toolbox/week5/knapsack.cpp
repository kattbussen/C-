#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &valueVec) {

	int valueVecSize = valueVec.size()+1;
	//int matrix[valueVecSize][W+1];	
	
	vector<vector<int>> matrix(valueVecSize, vector<int>(W));

	/*for(int i = 0; i <= W; i++) {
		matrix[0][i] = 0;
	}
	for(int i = 0; i < valueVecSize; i++) {
		matrix[i][0] = 0;
	}	*/

	for(int currValue = 1; currValue < valueVecSize; currValue++) {
		for(int currWeight = 1; currWeight <= W; currWeight++) {
			matrix[currValue][currWeight] = matrix[currValue-1][currWeight];

			if(valueVec[currValue-1] <= currWeight) {
				
				int val = matrix[currValue-1][currWeight - valueVec[currValue-1]] + valueVec[currValue-1];
				
				if(matrix[currValue][currWeight] < val) {
					matrix[currValue][currWeight] = val;
				}	
			}
		}
	}

	/*for(int i = 0; i < valueVecSize; i++) {
		for(int j = 0; j <= W; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}*/

	return matrix[valueVecSize-1][W];
}


int optimal_weight2(int W, const vector<int> &wv) {

	int valueVecSize = wv.size()+1;
	//int matrix[valueVecSize][W+1];	

	//vector<vector<int>> matrix(valueVecSize, vector<int>(W));
 
	int **matrix = 0;
	matrix = new int *[valueVecSize];
	for(int i = 0; i < valueVecSize; i++) {
		matrix[i] = new int[W];
	}

	for(int i = 0; i <= W; i++) {
		matrix[0][i] = 0;
	}
	for(int i = 0; i < valueVecSize; i++) {
		matrix[i][0] = 0;
	}	

	for(int i = 1; i < valueVecSize; i++) {
		for(int w = 1; w <= W; w++) {
			matrix[i][w] = matrix[i-1][w];

			if(wv[i-1] <= w) {
				
				int val = matrix[i-1][w - wv[i-1]] + wv[i-1];
				
				if(matrix[i][w] < val) {
					matrix[i][w] = val;
				}	
			}
		}
	}

	/*for(int i = 0; i < valueVecSize; i++) {
		for(int j = 0; j <= W; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}*/

	return matrix[valueVecSize-1][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight2(W, w) << '\n';
}
