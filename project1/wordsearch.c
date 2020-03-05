
/*
██▓     █    ██  ██▓  ██████
▓██▒     ██  ▓██▒▓██▒▒██    ▒
▒██░    ▓██  ▒██░▒██▒░ ▓██▄
▒██░    ▓▓█  ░██░░██░  ▒   ██▒
░██████▒▒▒█████▓ ░██░▒██████▒▒
░ ▒░▓  ░░▒▓▒ ▒ ▒ ░▓  ▒ ▒▓▒ ▒ ░
░ ░ ▒  ░░░▒░ ░ ░  ▒ ░░ ░▒  ░ ░
 ░ ░    ░░░ ░ ░  ▒ ░░  ░  ░
   ░  ░   ░      ░        ░
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// DO NOT INCLUDE OTHER LIBRARY!

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char** arr, int n);
/*char** arr, int n, */
void searchPuzzle(char** block, int blocksize, char** word, int listsize);

void toLowerCase(char *word);

char* left2right(char** puzzle, int row, int start, int characters);

char* right2left(char** puzzle, int row, int start, int characters);

char* downwards(char** puzzle, int row, int start, int characters);

char* downleft(char** puzzle, int row, int start, int characters);

char* downright(char** puzzle, int row, int start, int characters);

int areEqual(char *word, char* found, int size);

void l2rLower(char**puzzle, int row, int start, int size);
void r2lLower(char**puzzle, int row, int start, int size);
void downLower(char**puzzle, int row, int start, int size);
void dlLower(char**puzzle, int row, int start, int size);
void drLower(char**puzzle, int row, int start, int size);


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
	for(i=0; i<50; i++) {
		printf("%s\n", *(words + i));
	}
	printf("\n");

	// Print out original puzzle grid
    printf("Printing puzzle before search:\n");
    printPuzzle(block, bSize);
	printf("\n");


  searchPuzzle(block, bSize, words, 50);

  /*for (k = 0; k < 50; ++k) {
      searchPuzzle(block, 15, *(words+k));
  } */

  printf("\n");
  printf("Printing puzzle AFTER search:\n");
  printPuzzle(block, bSize);

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
void searchPuzzle(char** block, int blocksize, char** word, int listsize){
  int i, j, k, size;
  char *lr, *rl, *down, *dl, *dr;
  char firstletter;
  char tmp;

  for (k = 0; k < listsize; ++k) {
    toLowerCase(*(word+k));

    size = strlen(*(word+k));
    firstletter = *(*(word+k));

    for (i = 0; i < 15; ++i) {
      for (j = 0; j < 15; ++j) {

        //some more ravioli here
        if ( (int) *(*(block+i)+j) > 64 && (int) *(*(block+i)+j) < 91 ) {
          tmp = (char)((int) *(*(block+i)+j) +32);
        } else {
          tmp = *(*(block+i)+j);
        }
        //

        if ( tmp == firstletter ) {
          lr = left2right(block, i, j, size);
          //printf("%s\n", lr);
          rl = right2left(block, i, j, size);
          //printf("%s\n", rl);
          down = downwards(block, i, j, size);
          //printf("%s\n", down);
          dl = downleft(block, i, j, size);
          //printf("%s\n", dl);
          dr = downright(block, i, j, size);
          //printf("%s\n", dr);

          if (areEqual(*(word+k), down, size)) {
            printf("Found %s!\n", down);
            downLower(block, i, j, size);
          }

          if (areEqual(*(word+k), lr, size)) {
            printf("Found %s!\n", lr);
            l2rLower(block, i, j, size);

          }

          if (areEqual(*(word+k), dl, size)) {
            printf("Found %s!\n", dl);
            dlLower(block, i, j, size);
          }
          if (areEqual(*(word+k), dr, size)) {
            printf("Found %s!\n", dr);
            drLower(block, i, j, size);
          }

          if (areEqual(*(word+k), rl, size)) {
            printf("Found %s!\n", rl);
            r2lLower(block, i, j, size);
          }

        }
      }
    } // for loop end

  }

}

void toLowerCase(char *word) {
  char* p;
  for( p=word; *p!=0; p++ ) {
    if ((int)*p > 64 && (int)*p < 91) {
      *(p) = (char)((int)*p + 32);
    }
  }

}

char* left2right(char** puzzle, int row, int start, int characters) {
  int c = 0;
  int i;
  char*arr;

  arr = (char*)malloc(characters*sizeof(char));


  for (i = start; i < 15; ++i){
    if(c == characters) {
      break;
    } else {

      *(arr+i-start) = *(*(puzzle+row)+i);
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
      *(arr+i-start) = *(*(puzzle+row)+i);
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
      *(arr+i-row) = *(*(puzzle+i)+start);
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
      *(arr+i-row) = *(*(puzzle+i)+start);
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
      *(arr+i-row) = *(*(puzzle+i)+start);
    }
    c++;
    start++;
  }

  return arr;
}

int areEqual(char* word, char* found, int size) {
  int i;
  for(i = 0; i < size; ++i) {

    if(*(found+i) > 64 && *(found+i) < 91) {
      *(found+i) = (char)((int) *(found+i) + 32);
    } else {
      *(found+i) = *(found+i);
    }

    if(*(word+i) != *(found+i)) {
      return 0;
    }
  }
  return 1;
}

void l2rLower(char **puzzle, int row, int start, int size){
  int c = 0;
  int i;

  for (i = start; i < 15; ++i) {
    if (c == size ) {
      break;
    } else {
      if ((int)*(*(puzzle+row)+i) > 64 && (int)*(*(puzzle+row)+i) < 91) {
          *(*(puzzle+row)+i) = (char)((int)*(*(puzzle+row)+i)+32);
      } else {
          *(*(puzzle+row)+i) = *(*(puzzle+row)+i);
      }
    }
    c++;
  }
}

void r2lLower(char **puzzle, int row, int start, int size){
  int c = 0;
  int i;

  for (i = start; i >= 0; --i) {
    if (c == size) {
      break;
    } else {
      if ((int) *(*(puzzle+row)+i) > 64 && (int) *(*(puzzle+row)+i) < 91) {
          *(*(puzzle+row)+i) = (char)((int)*(*(puzzle+row)+i)+32);
      } else {
          *(*(puzzle+row)+i) = *(*(puzzle+row)+i);
      }

    }
    c++;
  }
}

void downLower(char **puzzle, int row, int start, int size){
  int c = 0;
  int i;

  for (i = row; i < 15; ++i) {
    if (c == size) {
      break;
    } else {
      if ((int) *(*(puzzle+i)+start) > 64 && (int) *(*(puzzle+i)+start) < 91) {
        *(*(puzzle+i)+start) = (char)((int)*(*(puzzle+i)+start)+32);
      } else {
        *(*(puzzle+i)+start) = *(*(puzzle+i)+start);
      }

    }
    c++;
  }

}

void dlLower(char **puzzle, int row, int start, int size){
  int c = 0;
  int i;

  for (i = row; i < 15; ++i) {
    if (c == size || start == 0) {
      break;
    } else {
      if ((int) *(*(puzzle+i)+start) > 64 && (int) *(*(puzzle+i)+start) < 91) {
        *(*(puzzle+i)+start) = (char)((int)*(*(puzzle+i)+start)+32);
      } else {
        *(*(puzzle+i)+start) = *(*(puzzle+i)+start);
      }

    }
    c++;
    start--;
  }

}

void drLower(char **puzzle, int row, int start, int size){
  int c = 0;
  int i;

  for (i = row; i < 15; ++i) {
    if (c == size || start == 14) {
      break;
    } else {
      if ((int) *(*(puzzle+i)+start) > 64 && (int) *(*(puzzle+i)+start) < 91) {
        *(*(puzzle+i)+start) = (char)((int)*(*(puzzle+i)+start)+32);
      } else {
        *(*(puzzle+i)+start) = *(*(puzzle+i)+start);
      }

    }
    c++;
    start++;
  }
}
