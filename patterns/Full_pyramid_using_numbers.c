/*
 *          1
 *        2 3 2
 *      3 4 5 4 3
 *    4 5 6 7 6 5 4
 *  5 6 7 8 9 8 7 6 5
 */

#include <stdio.h>

int main(void)
{
	int size_of_pattern, row, coloumn, space, temp, ref;

	scanf("%d", &size_of_pattern);

	space = (size_of_pattern - 1) * 2;

	for (row = 1; row <= size_of_pattern; row++) {
		for (coloumn = 0; coloumn < space; coloumn++)
			printf(" ");
		temp = row * 2 - 1;
		ref = row;

		for (coloumn = 1; coloumn <= temp; coloumn++) {
			if (coloumn < row)
				printf("%d ", ref++);
			if (coloumn >= row)
				printf("%d ", ref--);
		}
		space -= 2;
		printf("\n");
	}
	return 0;
}
