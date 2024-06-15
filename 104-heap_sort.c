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
 * sift_down - Applies the sift-down operation to maintain the heap property.
 * @array: An array of integers.
 * @size: The size of the heap.
 * @i: The index of the root element of the heap.
 */
void sift_down(int *array, size_t size, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap_ints(&array[i], &array[largest]);
		print_array(array, size);
		sift_down(array, size, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the sift-down Heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, i, 0);
	}
}

