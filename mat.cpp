// mat.cpp
#include <iostream>
#include <string>
#include <random>

using namespace std;

int main() {
	int m = 10;
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(0.0, 1.0);
	double n = distribution(generator);
	int** mat = [m][m];
	for (int i=0; i<m; i++) {
		for (int j=0; j<m; j++) {
			mat[i][j] = distribution(generator);
			cout << mat[i][j];
		}
	}
}