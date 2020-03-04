#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[MAX_NAME_LEN];
  unsigned long sid;
} Student;

void setName(Student* s, const char* name) {
/* fill me in */
  s->name = name;
}

unsigned long getStudentID(const Student* s) {
/* fill me in */
return s->sid;

}

void setStudentID(Student* s, unsigned long sid) {
/* fill me in */
  s->sid = sid;
}

Student* makeDefault(void) {
  Student s;
  setName(&s, "John");
  setStudentID(&s, 12345678);
  return &s;
}


void printArray(int*a, int n) {
  int i;
  for(i = 0; i < n; ++i) {
    printf("%d ", *(a+i));
  }
  printf("\n");
}

void swapArrays(int* a, int*b, int n) {
    int i;
    int *tmp = (int*)malloc(n*sizeof(int));
    for(i = 0; i < n; ++i) {
      *(tmp+i) = *(a+i);
    }

    for(i = 0; i < n; ++i) {
      *(a+i) = *(b+i);
      *(b+i) = *(tmp+i);
    }

}




char* changeCase(char* str) {
  char* p;
  char* result;
  result = (char*) malloc(strlen(str)*sizeof(char));
  strcpy(result, str);
  for( p=result; *p!=0; p++ ) {
    if ((int)*p > 64 && (int)*p < 91) {
      *(p) = (char)((int)*p + 32);
    }

  }
  return result;
}

void changeCase_by_ref( char** n ) {
  /* Fill-in */
  changeCase(*n);
}

void changeCase_name(char* names[], int i) {
  /* No not touch */
  changeCase_by_ref( &(names[i]) );
}




int main(int argc, char const *argv[]) {

  int *arr, *arr2;
  int n = 5;
  int i, j;

  arr = (int*)malloc(n*sizeof(int));
  arr2 = (int*)malloc(n*sizeof(int));

  for (i = 0; i < n; ++i) {
    *(arr+i) = i;
  }

  for (j = 0; j < n; ++j) {
    *(arr2+j) = j*2;
  }

  printArray(arr,n);
  printArray(arr2,n);
  swapArrays(arr,arr2,n);
  printArray(arr,n);
  printArray(arr2,n);

  char yeet[] = {'L', 'U', 'i', 's'};

  char* w;
  w = &yeet[0];
  w = changeCase(w);

  printf("%s\n", w);







  return 0;
}
