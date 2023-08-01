#include "../include/gaussian_elimination.h"
#include <iostream>

void GaussianElimination::solve(Matrix* a, Matrix* b, Matrix* x) {
	x->initialize(b->width, b->height, 0);
	
	for (int pivot = 0; pivot < a->width; pivot++) {
		if (a->matrix[pivot][pivot] == 0) {
			for (int i = pivot + 1; i < a->height; i++) {
				if (a->matrix[i][pivot] != 0) {
					a->swapRows(pivot, i);
					b->swapRows(pivot, i);
				}
			}
				
		}
		for (int i = pivot + 1; i < a->height; i++) {
			if (a->matrix[i][pivot] != 0) {
				double scalar = a->matrix[i][pivot] / a->matrix[pivot][pivot];
				a->multiplyRowScalar(scalar, pivot);
				b->multiplyRowScalar(scalar, pivot);
				a->subtractRows(pivot, i);
				b->subtractRows(pivot, i);
			}
		}
		
	}

	for (int i = b->height-1; i > -1; i--) {
		for (int j = i+1; j < a->width; j++) {
			x->matrix[i][0] = a->matrix[i][j] + x->matrix[i][0];
		}
		x->matrix[i][0] = (b->matrix[i][0] - x->matrix[i][0]) / a->matrix[i][i];

		a->multiplyColumnScalar(x->matrix[i][0], i);
	}
}