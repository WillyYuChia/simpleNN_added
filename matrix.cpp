#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
using namespace std;

matrix::matrix(int dim, bool random, bool strassen) : dim_(dim) {
	if (strassen) {
		int dim2 = 2;
		while (dim2 < dim)
			dim2 *= 2;
		dim_ = dim2;
	}
	
	data_ = new int[dim_ * dim_];
	if (!random) return;

	for (int i = 0; i < dim_ * dim_; i++)
		data_[i] = rand() % 10;
}

void matrix::print() {
	for (int i = 0; i < dim_; i++) {
		for (int j = 0; j < dim_; j++)
			cout << (*this)(i,j) << " ";
		cout << "\n";
	}
	cout << "\n";
}

matrix matrix::operator+(matrix b) {
	matrix c(dim_, false, false);
	for (int i = 0; i < dim_; i++)
		for (int j = 0; j < dim_; j++) 
			c(i,j) = (*this)(i,j) + b(i,j);
		
	return c;
}

matrix matrix::operator-(matrix b) {
	matrix c(dim_, false, false);
	for (int i = 0; i < dim_; i++)
		for (int j = 0; j < dim_; j++) 
			c(i,j) = (*this)(i,j) - b(i,j);
		
	return c;
}