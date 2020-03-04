#include <stdio.h>
#include <stdlib.h>

int** matMult(int **a, int **b, int size){
	int i, j, tmpa, tmpb = 0;
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.

	//do some boring stuff here
	int **res = (int**)malloc(size * sizeof(int*));
	for(i = 0; i < size; ++i) {
		*(res+i) = (int*)malloc(size*sizeof(int));
	}


	for(i = 0; i < size; ++i) {
		for(j = 0; j < size; ++j) {
			tmpa = *(*(a+i)+j);
			tmpb = *(*(b+i)+j);

			printf("Multiplying %d and %d \n", tmpa, tmpb);
			*(*(res+i)+j) = tmpa * tmpb;
		}
	}

	return res;

}

void printArray(int **arr, int n){
	int i, j = 0;
	for(i = 0; i < n; ++i) {
		for(j = 0; j < n; ++j) {
			printf("%d ", *(*(arr+i)+j));
		}
		printf("\n");
	}

}

int main() {
	int j, i = 0;
	int n = 5;
	int **matA, **matB, **matC;

	matA = (int**)malloc(n * sizeof(int*));
	matB = (int**)malloc(n * sizeof(int*));

	for(i = 0; i < n; ++i) {
		*(matA+i) = (int*)malloc(n*sizeof(int));
		*(matB+i) = (int*)malloc(n*sizeof(int));
	}

	for(i = 0; i < n; ++i) {
		for(j = 0; j < n; ++j) {
			*(*(matA+i)+j) = 0;
			*(*(matB+i)+j) = 0;
		}
		*(*(matA+i)+i) = i+1;
		*(*(matB+i)+i) = i+1;
	}



	printf("Matrix A: \n");
	printArray(matA, n);

	printf("Matrix B: \n");
	printArray(matB, n);
	printf("--------------\n");
	printf("Product of Matrix A and Matrix B: \n");
	matC = matMult(matA, matB, n);
	printArray(matC, n);


	// (3) Call printArray to print out the 2 arrays here.


	//(5) Call matMult to multiply the 2 arrays here.


	//(6) Call printArray to print out resulting array here.



    return 0;
}
