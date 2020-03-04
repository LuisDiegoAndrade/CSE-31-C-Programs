#include <stdio.h>
#include <stdlib.h>

void printArray(int**, int);

int main() {
	int i = 0, j = 0, n = 5;

	//allocates 5*sizeof(int*) bytes to store pointers.
	int **arr = (int**)malloc(n * sizeof(int*));

	// allocate memory for each array in arr
	for(i = 0; i < n; ++i) {
		*(arr+i) = (int*)malloc(n*sizeof(int));
	}

	// set all values to 0
	for(i = 0; i < n; ++i) {
		for(j = 0; j < n; ++j) {
			*(*(arr+i)+j) = 0;
		}
	}

	printArray(arr, n);

	// lil edit here to make a "diagonal matrix"
	for(i = 0; i < n; ++i) {
		*(*(arr+i)+i) = i+1;
	}
	printf("\n");


	printArray(arr, n);

	return 0;
}

void printArray(int ** array, int size){
	int i, j = 0;
	for(i = 0; i < size; ++i) {
		for(j = 0; j < size; ++j) {
			printf("%d ", *(*(array+i)+j));
		}
		printf("\n");
	}



}
