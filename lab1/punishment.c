#include <stdio.h>
#include <stdlib.h>

void printLine() {
  char s [36] = "C programming language is the best!";
  int i = 0;
  while (*(s+i) != 0){
    putchar(*(s+i));
    i++;
  }
}

int main(int argc, char const *argv[]) {
  printf("\n");


  printf("Enter # of lines to print: ");
  int amount, i;
  scanf("%d", &amount);

  if (amount < 0) {
    printf("Invalid input! \n");
    return 0;
  }
  printf("\n");

  int line;
  printf("Enter the line of the typo: ");
  scanf("%d", &line);
  printf("\n");

  if (line < 0 || line > amount) {
    printf("Invalid input! \n");
    return 0;
  }

  int j;
  for (j = 0; j < amount; ++j) {
    if (line-1 == j) {
      printf("C++ programming language is the best!\n");
    } else {printLine(); printf("\n");}
  }


  printf("\n");
  return 0;
}


/*for (i = 0; i < 6; ++i ){

  switch (i) {
    case '0': *(s+i) = 'h';
    case '1': *(s+i) = 'e';
    case '2': *(s+i) = 'l';
    case '3': *(s+i) = 'l';
    case '4': *(s+i) = 'o';
    case '5': *(s+i) = 0;
  }

} */
