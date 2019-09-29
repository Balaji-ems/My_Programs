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
	int input, row, coloumn, space = 0;

	scanf("%d", &input);

	for (row = 0; row < input * 2 - 1; row++) {

		if (row < input) {
			for (coloumn = 0; coloumn < space; coloumn++)
				printf(" ");

			for (coloumn = 0; coloumn < input; coloumn++)
				printf("*");

			space++;
			printf("\n");

			if (row == input - 1)
				space -= 2;

		} else {
			for (coloumn = 0; coloumn < space; coloumn++)
				printf(" ");

			for (coloumn = 0; coloumn < input; coloumn++)
				printf("*");

			space--;
			printf("\n");
		}
	}
}
