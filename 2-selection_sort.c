#include "sort.h"
/**
 *selection_sort - selec and sort node
 *@array: array
 *@size: size of node
 */

void selection_sort(int *array, size_t size)
{
	size_t step, i = 0;
	int min_idx, pass = 0;

	if (!array || size == 0)
		return;

	for (step = 0; step < size - 1; step++)
	{
		min_idx = step;
		for (i = step + 1; i < size; i++)
		{
			pass = 0;
			if (array[i] < array[min_idx])
			{
				min_idx = i;
				pass = 1;
				swap (&array[min_idx], &array[step]);
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
