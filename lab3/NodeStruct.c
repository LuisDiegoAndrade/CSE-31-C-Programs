
#include <stdio.h>
#include <stdlib.h>

struct Node {
    //note that this is NOT a pointer!
    int iValue;
    //note that this is NOT a pointer!
    float fValue ;
    //note that this is a pointer!
    struct Node *next;
};

int main() {

    struct Node* head;
    head = (struct Node*)malloc(sizeof(struct Node));

    head->iValue = 5;
    head->fValue = 3.14;




	  // Insert extra code here
	  printf("\nWhat head points to (struct Node): %p\n\n", head);
    printf("head->iValue = %d\n", head->iValue);
    printf("head->fValue = %f\n\n", head->fValue);
    printf("Address of 'head->iValue' or '&(*head).iValue': %p\n", &(*head).iValue );
    printf("Address of 'head->fValue' or '&(*head).fValue': %p\n\n", &(*head).fValue );
    printf("Address THAT 'head->next' or '(*head).next' is pointing to: %p\n", (*head).next );
    printf("Address OF 'head->next' or '(*head).next' is:  %p\n\n", &(*head).next );








	return 0;
}
