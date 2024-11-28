#include "sort.h"

/*
 * selection_sort - Selection sort algorithm
 * @array: an array to be sorted
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (!array)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (array[i] > array[min_idx])
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
