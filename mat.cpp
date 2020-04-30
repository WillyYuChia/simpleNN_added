
// mat.cpp
#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

double sec(clock_t start, clock_t end) {
    return (end-start)/1000.0;
}

int main() {
	int m = 1000;
	clock_t start = clock();
	string tab = "\t";

	std::default_random_engine generator;
	std::normal_distribution<double> distribution(0.0, 10.0);
	double n = distribution(generator);
	double mat[m][m];
	for (int i=0; i<m; i++) {
		for (int j=0; j<m; j++) {
			mat[i][j] = distribution(generator);
			//cout << i*m+j << ":\t" << mat[i][j] << endl;
		}
	}

	clock_t end = clock();
	double time = sec(start, end);
	cout << "Time:" << tab << time;
}
