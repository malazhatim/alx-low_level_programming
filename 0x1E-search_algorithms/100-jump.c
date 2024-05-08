#include "search_algos.h"

/**
  * jump_search - Searches for a value in a sorted array
  *               of integers using jump search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  * Return: If the value is not present or the array is NULL, -1
  */
int jump_search(int *array, size_t size, int value)
{
	size_t a, j, s;

	if (array == NULL || size == 0)
		return (-1);

	s = sqrt(size);
	for (a = j = 0; j < size && array[j] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", j, array[j]);
		a = j;
		j += s;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", a, j);

	j = j < size - 1 ? j : size - 1;
	for (; a < j && array[a] < value; a++)
		printf("Value checked array[%ld] = [%d]\n", a, array[a]);
	printf("Value checked array[%ld] = [%d]\n", a, array[a]);

	return (array[a] == value ? (int)a : -1);
}
