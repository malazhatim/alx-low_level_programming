#include "search_algos.h"

/**
  * interpolation_search - Searches for a value in a sorted array
  *                        of integers using interpolation search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  * Return: If the value is not present or the array is NULL, -1
  */
int interpolation_search(int *array, size_t size, int value)
{
	size_t a, f, t;

	if (array == NULL)
		return (-1);

	for (f = 0, t = size - 1; t >= f;)
	{
		a = f + (((double)(t - f) / (array[t] - array[f])) * (value - array[f]));
		if (a < size)
			printf("Value checked array[%ld] = [%d]\n", a; array[a]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", a);
			break;
		}

		if (array[a] == value)
			return (a);
		if (array[a] > value)
			t = a - 1;
		else
			f = a + 1;
	}

	return (-1);
}
