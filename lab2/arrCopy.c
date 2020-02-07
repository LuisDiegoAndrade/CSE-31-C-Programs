#include <stdio.h>
#include <stdlib.h>

void printArr(int *a, int size){
  int i;
  printf("printArr: ");
  for (i = 0; i < size; ++i) {
    printf("%d ",*(a+i));
  }
  printf("\n");
}

int* arrCopy(int *a, int size){
	int i, *copy;

  copy = (int *)malloc(sizeof(int) * size);
  for (i = 0; i < size; ++i){
    *(copy+i) = *(a+i);
  }

  return copy;
}

int main(){
    int n;
    int *arr;
    int *arr_copy;
    int i;
    printf("Enter size of array:\n");
    scanf("%d",&n);


    arr = (int *)malloc(sizeof(int)*n);
    for (i = 0; i < n; ++i){
      printf("Enter array content #%d: ", i+1);
      scanf("%d", arr+i);
      printf("\n");
    }


/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/

	//Print original array
    printArr(arr, n);


	//Copy array
    arr_copy = arrCopy(arr, n);

	//Print new array
    printArr(arr_copy, n);

    return 0;
}
