// Steve Tapia
// CSC-341

#include <stdio.h>
#include <stdlib.h>

// uninitialized data
int x; 
// initialized data
int y = 15;

int main(int argc, char *argv[])
{
	// Stack variables
	int *value;; 
	int i;

	// Heap variable
	value = (int *)malloc(sizeof(int)*5);

	printf("1. Argc Addres: %p \n", &argc);
	printf("2. Stack Address: %p \n", &i);
	printf("3. Heap Address: %p \n", &value);
	printf("4. Uninitialized data Adress: %p \n", &x);
	printf("5. Initialized data Address: %p \n", &y);

	return EXIT_SUCCESS;
}
