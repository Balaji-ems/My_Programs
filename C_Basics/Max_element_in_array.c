#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int sizeof_array, index, max_element;

A:
	printf("Enter a positive element greater than 1: ");
	scanf("%d", &sizeof_array);

	if (sizeof_array < 2)
		goto A;

	int *ptr = (int *) malloc (sizeof_array * sizeof(int));

	printf("\nEnter the elements to find the maximum\n");

	scanf("%d", ptr);
	max_element = *ptr;

	for(index = 1; index < sizeof_array; index++) {
		scanf("%d", ptr + index);
		if (*(ptr + index) > max_element)
			max_element = *(ptr + index);
	}

	printf("The maximum element is %d", max_element);
	return 0;
}
