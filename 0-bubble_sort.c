#include "sort.h"
/**
 *bubble_sort - sort number from min to max
 *@array: array
 *@size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	int pass = 0;
	size_t i, j;

	if (!array || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size -i - 1; j++)
		{
			pass = 0;
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				pass = 1;
				print_array(array, size);
			}
		}
		if (pass == 0)
			break;
	}
}

/**
 *swap - swaps node
 *@xp: keep node
 *@yp: change node
 */

void swap(int *xp, int *yp)
{
	int tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}
