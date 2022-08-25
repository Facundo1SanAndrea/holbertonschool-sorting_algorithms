#include "sort.h"

/**
 * quick_sort - sorts a list of ints order asc(Quick algorithm)
 * @array: array of elements
 * @size: amount of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_partion(array, 0, size - 1, size);
}

/**
 * quick_sort_partion - Recursive func that execute itself based on pivot item
 * @arr: array of elements
 * @start: starting index
 * @end: ending index
 * @size: amount of elements in array
 */
void quick_sort_partion(int *arr, int start, int end, size_t size)
{
	int i = start, j = start, pivot = end;

	while (j <= pivot)
	{
		if (arr[j] > arr[pivot])
			j++;
		else
		{
			if (i != j)
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}

			if (j == pivot)
				break;

			j = i + 1;
			i = j;
		}
	}
	if ((i - start) > 1)
		quick_sort_partion(arr, start, i - 1, size);
	if ((end - i) > 1)
		quick_sort_partion(arr, i + 1, end, size);
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
