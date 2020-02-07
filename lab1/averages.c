#include <stdio.h>


int main(int argc, char const *argv[]) {

  int input = 1;
  int posSum, negSum, nc, pc= 0;

  printf("\n");
  while (input != 0) {
    printf("Enter an integer: ");
    scanf("%d", &input);
    if (input < 0) {negSum += input; nc++;}
    else if (input > 0) {posSum += input; pc++;}
  }

  if (pc != 0){printf("Positive average: %d\n", posSum/pc);}
  if (nc != 0){printf("Negative average: %d\n", negSum/nc);}
  printf("\n");
  return 0;
}
