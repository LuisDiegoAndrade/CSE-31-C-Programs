
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int iValue;
    float fValue ;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;

	// Insert extra code here
	  printf("%p \n", head);
    printf("%d\n", head->iValue);
    printf("%f\n", head->fValue);

    





	return 0;
}
