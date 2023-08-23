#include "main.h"

/**
 * reverse_array - reverses an array of integers
 * @a: array to be reversed
 * @n: number of elements in the array
 */
void reverse_array(int *a, int n)
{
	int d, b, c;

	b = n - 1;

	for (d = 0; d < n / 2; d++)
	{
		c = a[d];
		a[d] = a[b];
		a[b--] = c;
	}
}
