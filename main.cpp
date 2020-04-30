#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "matrix.h"

typedef pair<matrix, long> result;

int cut = 64;

matrix mult_std(matrix a, matrix b) {
	matrix c(a.dim(), false, false);
	for (int i = 0; i < a.dim(); i++)
		for (int k = 0; k < a.dim(); k++)
			for (int j = 0; j < a.dim(); j++)
				c(i,j) += a(i,k) * b(k,j);
	
	return c;
}

matrix get_part(int pi, int pj, matrix m) {
	matrix p(m.dim() / 2, false, true);
	pi = pi * p.dim();
	pj = pj * p.dim();
	
	for (int i = 0; i < p.dim(); i++)
		for (int j = 0; j < p.dim(); j++)
			p(i,j) = m(i + pi,j + pj);
			
	return p;
}

void set_part(int pi, int pj, matrix* m, matrix p) {
	pi = pi * p.dim();
	pj = pj * p.dim();
	
	for (int i = 0; i < p.dim(); i++)
		for (int j = 0; j < p.dim(); j++)
			(*m)(i + pi,j + pj) = p(i,j);
}

matrix mult_strassen(matrix a, matrix b) {
	if (a.dim() <= cut)
		return mult_std(a, b);

	matrix a11 = get_part(0, 0, a);
	matrix a12 = get_part(0, 1, a);
	matrix a21 = get_part(1, 0, a);
	matrix a22 = get_part(1, 1, a);
	
	matrix b11 = get_part(0, 0, b);
	matrix b12 = get_part(0, 1, b);
	matrix b21 = get_part(1, 0, b);
	matrix b22 = get_part(1, 1, b);
	
	matrix m1 = mult_strassen(a11 + a22, b11 + b22); 
	matrix m2 = mult_strassen(a21 + a22, b11);
	matrix m3 = mult_strassen(a11, b12 - b22);
	matrix m4 = mult_strassen(a22, b21 - b11);
	matrix m5 = mult_strassen(a11 + a12, b22);
	matrix m6 = mult_strassen(a21 - a11, b11 + b12);
	matrix m7 = mult_strassen(a12 - a22, b21 + b22);
	
	matrix c(a.dim(), false, true);
	set_part(0, 0, &c, m1 + m4 - m5 + m7);
	set_part(0, 1, &c, m3 + m5);
	set_part(1, 0, &c, m2 + m4);
	set_part(1, 1, &c, m1 - m2 + m3 + m6);
	
	return c;
}

pair<matrix, long> run(matrix (*f)(matrix, matrix), matrix a, matrix b) {
	struct timeval start, end;
	
	gettimeofday(&start, NULL);
	matrix c = f(a, b);
	gettimeofday(&end, NULL);
	long e = (end.tv_sec * 1000 + end.tv_usec / 1000);
	long s =(start.tv_sec * 1000 + start.tv_usec / 1000);
	
	return pair<matrix, long> (c, e - s);
}

int main() {
	/* test cut of for strassen
	/*
	for (cut = 2; cut <= 512; cut++) {
		matrix a(512, true, true);
		matrix b(512, true, true);
		result r = run(mult_strassen, a, b);
		cout << cut << " " << r.second << "\n";
	}
	*/
	
	/* performance test: standard and strassen */
	for (int dim = 0; dim <= 1024; dim += 64) {
		matrix a(dim, true, false);
		matrix b(dim, true, false);
		result std = run(mult_std, a, b);
		matrix c(dim, true, true);
		matrix d(dim, true, true);
		result strassen = run(mult_strassen, c, d);
		cout << dim << " " << std.second << " " << strassen.second << "\n";
	}
}