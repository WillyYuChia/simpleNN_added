#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;

class matrix
{
public:
    matrix(int dim, bool random, bool strassen);
    
    inline int dim() {
			return dim_;
		}
		inline int& operator()(unsigned row, unsigned col) {
			return data_[dim_*row + col];
		}

		inline int operator()(unsigned row, unsigned col) const {
			return data_[dim_*row + col];
		}
		
		void print();
		matrix operator+(matrix b);
		matrix operator-(matrix b);

private:
    int dim_;
    int* data_;
};

#endif