#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int sizeof_array, index, max_element;

A:
	printf("Enter a element count (greater than 2) : ");
	scanf("%d", &sizeof_array);

	if (sizeof_array < 2)
		goto A;

	int *ptr = (int *) malloc(sizeof_array * sizeof(int));

	if (!ptr) {
		printf("Memory allocation failed\n");
		return 0;
	}

	printf("Enter the elements to find maximum : ");

	scanf("%d", ptr);
	max_element = *ptr;

	for (index = 1; index < sizeof_array; index++) {
		scanf("%d", ptr + index);
		if (*(ptr + index) > max_element)
			max_element = *(ptr + index);
	}

	printf("The maximum element is %d\n", max_element);
	return 0;
}
