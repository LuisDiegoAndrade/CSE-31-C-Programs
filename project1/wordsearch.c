#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// DO NOT INCLUDE OTHER LIBRARY!

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char** arr, int n);
/*char** arr, int n, */
void searchPuzzle(char** list, int listSize);

void toUpperCase(char *word);

char* left2right(char** puzzle, int row, int start, int characters);

char* right2left(char** puzzle, int row, int start, int characters);

char* downwards(char** puzzle, int row, int start, int characters);

char* downleft(char** puzzle, int row, int start, int characters);

char* downright(char** puzzle, int row, int start, int characters);





// Main function, DO NOT MODIFY!!!
int main(int argc, char **argv) {
    int bSize = 15;
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
		return 2;
	}
    int i, j;
    FILE *fptr;
    char **block = (char**)malloc(bSize * sizeof(char*));
	char **words = (char**)malloc(50 * sizeof(char*));

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

	// Read puzzle block into 2D arrays
    for(i=0; i<bSize; i++){
        *(block+i) = (char*)malloc(bSize * sizeof(char));

        fscanf(fptr, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(block+i), *(block+i)+1, *(block+i)+2, *(block+i)+3, *(block+i)+4, *(block+i)+5, *(block+i)+6, *(block+i)+7, *(block+i)+8, *(block+i)+9, *(block+i)+10, *(block+i)+11, *(block+i)+12, *(block+i)+13, *(block+i)+14 );
    }
	fclose(fptr);

	// Open file for reading word list
	fptr = fopen("states.txt", "r");
	if (fptr == NULL) {
        printf("Cannot Open Words File!\n");
        return 0;
    }

	// Save words into arrays
	for(i=0; i<50; i++){
		*(words+i) = (char*)malloc(20 * sizeof(char));
		fgets(*(words+i), 20, fptr);
	}

	// Remove newline characters from each word (except for the last word)
	for(i=0; i<49; i++){
		*(*(words+i) + strlen(*(words+i))-2) = '\0';
	}

	// Print out word list
	printf("Printing list of words:\n");
	for(i=0; i<50; i++){
		printf("%s\n", *(words + i));
	}
	printf("\n");

	// Print out original puzzle grid
    printf("Printing puzzle before search:\n");
    printPuzzle(block, bSize);
	printf("\n");
  searchPuzzle(words,50);
  printf("\n");
  printf("%s\n", *(words));

  toUpperCase(*(words));
  printf("%s\n", *(words));

  char* lr = downright(block, 0, 14, 3);
  printf("%s\n", lr);




	// Call searchPuzzle to find all words in the puzzle
	//searchPuzzle(block, bSize, words, 50);
	//printf("\n");

	// Print out final puzzle grid with found words in lower case
    //printf("Printing puzzle after search:\n");
    //printPuzzle(block, bSize);
	printf("\n");

    return 0;
}

//15x15 matrix ;)
void printPuzzle(char** arr, int n){
	// This function will print out the complete puzzle grid (arr). It must produce the output in the SAME format as the samples in the instructions.
	// Your implementation here
  int j, i;
  for(i = 0; i < n; ++i){
    for(j = 0; j < n; ++j){
      printf("%c ", *(*(arr+i)+j));
    }
    printf("\n");
  }


}
/*char** arr,int n,*/
void searchPuzzle(char** list, int listSize){
  int i, j;
  char ** search_matrix;

}

void toUpperCase(char *word) {
  char* p;
  for( p=word; *p!=0; p++ ) {
    if ((int)*p > 96 && (int)*p < 123) {
      *(p) = (char)((int)*p - 32);
    }
  }

}

char* left2right(char** puzzle, int row, int start, int characters) {
  int c = 0;
  int i;
  char*arr;

  arr = (char*)malloc(characters*sizeof(char));

  /*for (p = *(*(puzzle+row)+start); p !=0; p++) {

  }*/
  for (i = start; i < 15; ++i){
    if(c == characters) {
      break;
    } else {

      *(arr+i) = *(*(puzzle+row)+i);
    }
    c++;

  }
  return arr;
}

char* right2left(char** puzzle, int row, int start, int characters) {
  int c = 0;
  int i;
  char*arr;

  arr = (char*)malloc(characters*sizeof(char));

  /*for (p = *(*(puzzle+row)+start); p !=0; p++) {

  }*/
  for (i = start; i >= 0; --i){
    if(c == characters) {
      break;
    } else {
      *(arr+i) = *(*(puzzle+row)+i);
    }
    c++;

  }
  return arr;
}

char* downwards(char** puzzle, int row, int start, int characters) {
  int c = 0;
  int i, j;
  char*arr;

  arr = (char*)malloc(characters*sizeof(char));

  for (i = row; i < 15; ++i) {
    if (c == characters) {
      break;
    } else {
      *(arr+i) = *(*(puzzle+i)+start);
    }
    c++;
  }
  return arr;
}



char* downleft(char** puzzle, int row, int start, int characters) {
  int c = 0;
  int i, j;
  char*arr;

  arr = (char*)malloc(characters*sizeof(char));

  for (i = row; i < 15; ++i) {
    if (c == characters || start == 0) {
      break;
    } else {
      *(arr+i) = *(*(puzzle+i)+start);
    }
    c++;
    start--;
  }

  return arr;
}

char* downright(char** puzzle, int row, int start, int characters) {
  int c = 0;
  int i, j;
  char*arr;

  arr = (char*)malloc(characters*sizeof(char));

  for (i = row; i < 15; ++i) {
    if (c == characters || start == 14) {
      break;
    } else {
      *(arr+i) = *(*(puzzle+i)+start);
    }
    c++;
    start++;
  }

  return arr;
}
