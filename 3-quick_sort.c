#include "sort.h"

void quickSort(int *array, int start, int end, size_t length);
int partition(int *array, int start, int end, size_t length);

/**
 * quick_sort - quick sort entry point
 * @array: unsorted array
 * @size: size of unsorted array
 */

void quick_sort(int *array, size_t size)
{	
	if (!array)
		return;
	quickSort(array, 0, size - 1, size);
}

/**
 * quickSort - a helper function
 * @array: an array to be sorted
 * @start: the beginning of the array
 * @end: the end of the array
 * @length: the length of the entire array length
 */

void quickSort(int *array, int start, int end, size_t length)
{
	int pivot;

	if (end <= start)
		return;
	pivot = partition(array, start, end, length);
	quickSort(array, start, pivot - 1, length);
	quickSort(array, pivot + 1, end, length);
}

/**
 * partition - sorting and putting the pivot in its correct position
 * @array: an array to be sorted
 * @start: the beginning of the partition
 * @end: the end of the partition
 * @length: the length of the entire array
 * Return: is to return the current pivot index
 */

int partition(int *array, int start, int end, size_t length)
{
	int i, j, temp, pivot = array[end];

	i = start - 1;
	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	i++;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, length);
	return (i);
}
