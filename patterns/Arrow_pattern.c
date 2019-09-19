// SPDX-License-Identifier: GPL-2.0

/*
 *
 *    * * * * *
 *     * * * * *
 *      * * * * *
 *       * * * * *
 *        * * * * *
 *       * * * * *
 *      * * * * *
 *     * * * * *
 *    * * * * *
 *
 */

#include<stdio.h>
int main(void)
{
	int num, i, j, space = 0;

	scanf("%d", &num);   // user input for the size of the pattern
	// the pattern will have 2*num-1 rows
	for (i = 0; i < num * 2 - 1; i++) {
		// first half of the pattern
		if (i < num) {
			for (j = 0; j < space; j++)
				printf(" ");

			for (j = 0; j < num; j++)
				printf("*");

			space++;
			printf("\n");

			if (i == num - 1)
				space -= 2;
		}
		// second half of the pattern
		else {
			for (j = 0; j < space; j++)
				printf(" ");

			for (j = 0; j < num; j++)
				printf("*");

			space--;
			printf("\n");
		}
	}
}
