// SPDX-License-Identifier: GPL-3.0

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
	int input, row, coloumn, test;

	scanf("%d", &input);
	for (row = 0; row < input; row++) {
		for (coloumn = 0; coloumn < input; coloumn++) {

			test = coloumn + row == input - 1;
			if (row == 0 || row == input-1 || test)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
