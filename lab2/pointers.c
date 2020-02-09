#include <stdio.h>
#include <stdlib.h>
//comment out if not using emscripten compiler
//Additionaly, also comment out "EMSCRIPTEN_KEEPALIVE" if not compiling to wasm
#include <emscripten/emscripten.h>

EMSCRIPTEN_KEEPALIVE
int main() {

  int x,y, *px, *py = 0;
  int* arr;
  int *arrayMalloc;

  int array [10] = {1,2,3,4,5,6,7,8,9,10};
  arr = &array[0];

  arrayMalloc = (int *)malloc(sizeof(int) * 10);

  int j;
  for (j = 0; j < 10; j++) {
    *(arr+j) = j+1;
  }

  px = &x;
  py = &y;

  printf("\%p \%p \%p \%p \n", &x, &y, px, py);

  int i;
  for(i = 0; i < 10; ++i){
    printf("%d\n", *(arr+i));
  }
  printf("%p %p\n", arr, &arr[0]);
  //printf("%d %d \n",px,py);
  //printf("\%p \%p", &x, &y);


return 0;
}
