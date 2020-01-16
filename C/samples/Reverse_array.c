#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int array_size, index, *ptr, left, right;

	printf("Enter the array size : ");
	scanf("%d", &array_size);

	ptr = (int *)malloc(array_size * sizeof(int));

	if (!ptr) {
		printf("Memory allocation failed\n");
		return 0;
	}

	printf("Enter the array elements : ");
	for (index = 0; index < array_size; index++)
		scanf("%d", ptr + index);

	left = 0;
	right = array_size - 1;

	while (left < right) {
		*(ptr + left) = (*(ptr + left) + *(ptr + right))
			       - (*(ptr + right) = *(ptr + left));
		left++;
		right--;
	}

	printf("The reversed array is: ");
	for (index = 0; index < array_size; index++)
		printf("%d ", *(ptr+index));
	printf("\n");

	free(ptr);
	return 0;

}
