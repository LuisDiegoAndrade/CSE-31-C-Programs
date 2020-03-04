#include <stdio.h>

int main() {
	int i;
	int four_ints[4];
	char* four_c;

	for(i=0; i<4; i++)
        four_ints[i] = 2;

	printf("%d\n", four_ints[0]);

  four_c = (char*)four_ints;

	for(i=0; i<4; i++)
        four_c[i] = 'A'; // ASCII value of 'A' is 65 or 0x41 in Hex.

  printf("four_ints address: %p\nfour_c address %p \n", &four_ints, four_c);
	printf("four_ints values and address: \n");
	printf("----------------------\n");
	for(i=0; i<4; i++) {
        printf("%x %d\n",  four_ints[i], &four_ints[i]);

	}

	printf("four_c values: \n");
	printf("----------------------\n");
	for(i=0; i<4; i++) {
				printf("%x %d\n",  *(four_c+i), four_c+i);
	}

	//printf("%x\n", four_ints[0]);
	printf("Size of char: %lu bytes\nSize of int: %lu bytes\n", sizeof(char), sizeof(int));



	return 0;

}
