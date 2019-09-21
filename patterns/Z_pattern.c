// SPDX-License-Identifier: GPL-3.0


/*  Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 *  Everyone is permitted to copy and distribute verbatim copies
 *  of this license document, but changing it is not allowed.
 */

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
