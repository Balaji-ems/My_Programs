/*
 *
 *  *****
 *     *
 *    *
 *   *
 *  *****
 *
 */

#include <stdio.h>

int main(void)

{
	int input, row, coloumn;

	scanf("%d", &input);
	for (row = 0; row < input; row++) {
		for (coloumn = 0; coloumn < input; coloumn++) {

			if (row == 0 || row == input-1 ||
				coloumn + row == input - 1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
