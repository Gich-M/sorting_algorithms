#include "sort.h"

/**
 * merge - Merges two sorted subarrays into a single sorted array.
 * @array: The array to be sorted.
 * @left: The left subarray.
 * @right: The right subarray.
 * @size: The total size of the array.
 */
void merge(int *array, int *left, int *right, size_t size)
{
	size_t mid = size / 2;
	size_t left_size = mid;
	size_t right_size = size - mid;
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n[left]: ");
	for (i = 0; i < left_size; i++) 
{
		printf("%d", left[i]);
		if (i < left_size - 1)
			printf(", ");
	}

	printf("\n[right]: ");
	for (j = 0; j < right_size; j++) 
{
		printf("%d", right[j]);
		if (j < right_size - 1)
			printf(", ");
	}
	printf("\n");

	i = 0;
	j = 0;
	k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}

	printf("[Done]: ");
	for (i = 0; i < size; i++) 
{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * merge_sort_recursive - Recursively sorts an array using merge sort.
 * @array: The array to be sorted.
 * @temp: A temporary array for merging.
 * @size: The size of the array.
 */
void merge_sort_recursive(int *array, int *temp, size_t size)
{
	size_t mid, i;
	int *left, *right;

	if (size <= 1)
		return;

	mid = size / 2;
	left = temp;
	right = temp + mid;

	for (i = 0; i < mid; i++)
		left[i] = array[i];

	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort_recursive(left, array, mid);
	merge_sort_recursive(right, array, size - mid);
	merge(array, left, right, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size <= 1)
		return;

	temp = malloc(size * sizeof(int));
	if (!temp)
		return;

	merge_sort_recursive(array, temp, size);
	free(temp);
}

