#include "sort.h"
/**
 * swap_ints - Swap two integers in an array.
 * @a- the first integer to swap.
 * @b- the second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array it is an array of integers.
 * @size is size of the array.
 *
 * Description it Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;
    if (array == NULL || size < 2)
        return;
    for (gap = 1; gap < (size / 3);)
        gap = gap * 3 + 1;
    for (; gap >= 1; gap /= 3)
    {
        for (i = gap; i < size; i++)
        {
            j = i;
            while (j >= gap && array[j - gap] > array[j])
            {
                swap_ints(array + j, array + (j - gap));
                j -= gap;
            }
        }
        print_array(array, size);
    }
}
