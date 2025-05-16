#include <stdlib.h>
#include "sort.h"

void counting_sort(int *array, size_t size)
{
    int *count = NULL;
    int *output = NULL;
    int j, max_val = array[0];
    size_t i;

    output = malloc(sizeof(*output) * size);
    count = malloc(sizeof(*count) * (max_val + 1));
    if (!count || !output)
    {
        free(count);
        free(output);
    }
    i = 1;
    while (i < size)
    {
        if (array[i] > max_val)
            max_val = array[i];
        i++;
    }
    if (count == NULL)
        return;
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
