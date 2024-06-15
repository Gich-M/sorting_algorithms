#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * bitonic_merge - Recursively sorts a bitonic sequence in ascending order.
 * @array: An array of integers.
 * @low: The starting index of the sequence.
 * @count: The number of elements in the sequence.
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
    size_t i;

    if (count > 1)
    {
        size_t k = count / 2;

        printf("Merging [%lu/%lu] (%s):\n", count, count * 2, dir ? "UP" : "DOWN");
        for (i = low; i < low + k; i++)
        {
            if (dir == (array[i] > array[i + k]))
            {
                swap_ints(&array[i], &array[i + k]);
            }
        }
        print_array(array + low, count);
        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort_rec - Recursively builds a bitonic sequence and sorts it.
 * @array: An array of integers.
 * @low: The starting index of the sequence.
 * @count: The number of elements in the sequence.
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_sort_rec(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {

        size_t k = count / 2;

        printf("Merging [%lu/%lu] (%s):\n", count, count * 2, dir ? "UP" : "DOWN");
        bitonic_sort_rec(array, low, k, 1);
        bitonic_sort_rec(array, low + k, k, 0);
        bitonic_merge(array, low, count, dir);
        printf("Result [%lu/%lu] (%s):\n", count, count * 2, dir ? "UP" : "DOWN");
        print_array(array + low, count);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the Bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_rec(array, 0, size, 1);
}
