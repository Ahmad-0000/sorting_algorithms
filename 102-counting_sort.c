#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void counting_sort(int *array, size_t size)
{
    int *count = NULL;
    int *output = NULL;
    int j, max_val;
    size_t i;

    if (array == NULL || size == 1)
        return;
    i = 1;
    max_val = array[0];
    while (i < size)
    {
        if (array[i] > max_val)
            max_val = array[i];
        i++;
    }
    output = malloc(sizeof(*output) * size);
    if (output == NULL)
        return;
    count = malloc(sizeof(*count) * (max_val + 1));
    if (count == NULL)
    {
        free(output);
        return;
    }
    for (j = 0; j < max_val + 1; j++)
        count[j] = 0;
    for (i = 0; i < size; i++)
        count[array[i]] += 1;
    for (j = 1; j < max_val + 1; j++)
        count[j] += count[j - 1];
    print_array(count, max_val + 1);
    for (j = size - 1; j >= 0; j--)
    {
        count[array[j]] -= 1;
        output[count[array[j]]] = array[j];
    }
    for (i = 0; i < size; i++)
        array[i] = output[i];
    free(count);
    free(output);
}
