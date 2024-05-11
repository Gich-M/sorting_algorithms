#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 *               bubble sort algorithm.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len;
	bool bubbly = true;

	if (array == NULL || size < 2)
		return;

	len = size;
	while (bubbly)
	{
		bubbly = false;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(&array[i], &array[i + 1]);
				print_array(array, size);
				bubbly = true;
			}
		}
		len--;
	}
}

