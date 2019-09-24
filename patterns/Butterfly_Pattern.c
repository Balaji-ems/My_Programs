// SPDX-License-Identifier: GPL-3.0

/*
 *
 *  *     *
 *  **   **
 *  *** ***
 *  *******
 *  *** ***
 *  **   **
 *  *     *
 *
 */

#include<stdio.h>

int main(void)
{
	int row, coloumn, input, center, star_count, space;

	scanf("%d", &input);

	center = input / 2;
	star_count = 1;
	space = input - 2;

	for (row = 0; row < input; row++) {

		if (row == center) {

			for (coloumn = 0; coloumn < input; coloumn++)
				printf("*");

			space = 1;
			star_count = input / 2;

		} else if (row < center) {

			for (coloumn = 0; coloumn < star_count; coloumn++)
				printf("*");

			for (coloumn = 0; coloumn < space; coloumn++)
				printf(" ");

			for (coloumn = 0; coloumn < star_count; coloumn++)
				printf("*");

			star_count++;
			space -= 2;

		} else if (row > center) {

			for (coloumn = 0; coloumn < star_count; coloumn++)
				printf("*");

			for (coloumn = 0; coloumn < space; coloumn++)
				printf(" ");

			for (coloumn = 0; coloumn < star_count; coloumn++)
				printf("*");

			space += 2;
			star_count--;
		}
		printf("\n");
	}
}
