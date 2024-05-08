#include "search_algos.h"

/**
 * linear_search - implement  linear search  algo
 * @array: given array to search in
 * @size: size of the array
 * @value: value to search for
 * Return: first index or -1
 */
int linear_search(int *array, size_t size, int value)
{
	size_t a;

	if (array == NULL)
		return (-1);
	for (a = 0; a < size; a++)
	{
		printf("Value checked array[%lu] = [%d]\n", a, array[a]);
		if (array[a] == value)
			return (a);

	}
	return (-1);

}
