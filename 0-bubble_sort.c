#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Bubble sorting algorithm
 * @array: an array to be sorted
 * @size: the size of tha array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap = 0;

	if (!array)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = 1;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
		if (!swap)
			return;
	}
}
