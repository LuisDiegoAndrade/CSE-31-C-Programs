#include <stdio.h>
#include <stdlib.h>
//comment out if not using emscripten compiler
//Additionaly, also comment out "EMSCRIPTEN_KEEPALIVE" if not compiling to wasm
#include <emscripten/emscripten.h>

EMSCRIPTEN_KEEPALIVE
int* Int_Array(int size) {
  int* a = (int*)malloc(sizeof(int)*size);
  return a;
}

EMSCRIPTEN_KEEPALIVE
int Int_Get(int* array, int index) {
  return *(array+index);
}

EMSCRIPTEN_KEEPALIVE
void Int_Set(int* array, int index, int value) {
  *(array+index) = value;
}


EMSCRIPTEN_KEEPALIVE
int are_they_equal() {
  int coolArr[10] = {1,2,3,4,5,6,7,8,9,10};
  int* arr = &coolArr[0];

  if (&coolArr[0]-arr == 0) {
    return (1);
  }
  return (0);
}
