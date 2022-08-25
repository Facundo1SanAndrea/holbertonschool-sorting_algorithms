#include "sort.h"

void quick_sort_partion(int *arr, int start, int end, size_t size);
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

void quick_sort_partion(int *arr, int start, int end, size_t size)
{
	int i = start, j = start, pivot = end;

	printf("empezo de nuevo\n");	
	
	while (j <= pivot)
	{
		/*printf("i:     <%d> %d\n", i, arr[i]);
		printf("j:     <%d> %d\n", j, arr[j]);
		printf("pivot: <%d> %d\n", pivot, arr[pivot]);*/
		if (arr[j] > arr[pivot])
		{
			/*printf("<%d> es > a <%d>\n", arr[j], arr[pivot]);*/
			j++;
		}
		else
		{
			/*printf("<%d> es <= a <%d>\n", arr[j], arr[pivot]);*/
			if (i != j)
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}

			if (j == pivot)
				break;
			else
			{
				j = i + 1;
				i = j;
			}
		}
	}
	if (((i - 1) - start) > 1)
	{
		/*printf("particion de la izquierda\n");*/
		quick_sort_partion(arr, start, i - 1, size);
	}
	if ((end - (i - 1)) > 1)
	{
		/*printf("particion de la derecha\n");*/
		quick_sort_partion(arr, i + 1, end, size);
	}
}

void swap(int *xp, int *yp)
{
	int tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}