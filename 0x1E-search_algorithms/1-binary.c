#include "search_algos.h"

/**
 * binary_search - implement  binary search  algo
 * @array: given array to search in
 * @size: size of the array
 * @value: value to search for
 * Return: first index or -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t a = 0;
	size_t l = 0, r = size - 1, m;

	if (array == NULL)
		return (-1);
	while (l <= r)
	{
		printf("Searching in array: ");
		for (a = l; a < r; a++)
		{
			printf("%a, ", array[a]);
		}
		printf("%a\n", array[r]);
		m = (l + r) / 2;
		if (array[m] < value)
		{
			l = m + 1;
		}
		else if (array[m] > value)
		{
			r = m - 1;
		}
		else
		{
			return (m);
		}

	}
	return (-1);
}
