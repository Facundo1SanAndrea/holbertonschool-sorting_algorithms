#include "sort.h"
/**
 *selection_sort - selec and sort node
 *@array: array
 *@size: size of node
 */

void selection_sort(int *array, size_t size)
{
	size_t step, i = 0;
	size_t min_idx, pass = 0;

	if (!array || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (step = i + 1; step < size; step++)
		{
			if (array[step] < array[min_idx])
				min_idx = step;
		}
		if (min_idx != i)
		{
			pass = array[i];
			array[i] = array[min_idx];
			array[min_idx] = pass;
			print_array(array, size);
		}
	}
}
