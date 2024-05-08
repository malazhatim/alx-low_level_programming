#include "search_algos.h"

/**
  * _binary_search - Searches for a value in a sorted array
  *                  of integers using binary search.
  * @array: A pointer to the first element of the array to search.
  * @left: The starting index of the [sub]array to search.
  * @right: The ending index of the [sub]array to search.
  * @value: The value to search for.
  * Return: If the value is not present or the array is NULL
  */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t a;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (a = left; a < right; a++)
			printf("%d, ", array[a]);
		printf("%d\n", array[a]);

		a = left + (right - left) / 2;
		if (array[a] == value)
			return (a);
		if (array[a] > value)
			right = a - 1;
		else
			left = a + 1;
	}

	return (-1);
}

/**
  * exponential_search - Searches for a value in a sorted array
  *                      of integers using exponential search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  * Return: If the value is not present or the array is NULL, -1
  */
int exponential_search(int *array, size_t size, int value)
{
	size_t b = 0, r;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (b = 1; b < size && array[b] <= value; b = b * 2)
			printf("Value checked array[%ld] = [%d]\n", b, array[b]);
	}

	r = b < size ? b : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", b / 2, r);
	return (_binary_search(array, b / 2, r, value));
}
