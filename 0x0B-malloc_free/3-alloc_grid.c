#include <stdlib.h>
#include "main.h"

/**
 * **alloc_grid - creates a two dimensional array of ints
 * @width: width of the matrix
 * @height: height of the matrix
 *
 * Return: pointer to the created matrix (Success)
 * or NULL (Error)
 */
int **alloc_grid(int width, int height)
{
	int **a;
	int b, c;

	if (height <= 0 || width <= 0)
		return (NULL);

	a = (int **) malloc(sizeof(int *) * height);

	if (a == NULL)
		return (NULL);

	for (b = 0; b < height; b++)
	{
		a[b] = (int *) malloc(sizeof(int) * width);
		if (a[b] == NULL)
		{
			free(a);
			for (c = 0; c <= b; c++)
				free(a[b]);
			return (NULL);
		}
	}

	for (a = 0; a < height; a++)
	{
		for (b = 0; b < width; b++)
		{
			a[b][c] = 0;
		}
	}
	return (a);
}
