/*
 * In order to align the data in memory, one or more empty bytes
 * (addresses) are inserted (or left empty) between memory addresses
 * which are allocated for other structure members while memory
 * allocation. This concept is called structure padding.
 */

/* Structure 1 to contain some variables */

struct first {
	int *ptr;
	char a;
	char b;
};

/* Structure 2 contains the same variables
 * But the variable are arranged in different order
 */

struct second {
	char a;
	int *ptr;
	char b;
};

#include <stdio.h>

int main(void)
{
	struct first var1;
	struct second var2;

	printf("The Size of firt structure is %ld\n", sizeof(var1));
	printf("The size of second srtucture is %ld\n", sizeof(var2));

	return 0;

}
