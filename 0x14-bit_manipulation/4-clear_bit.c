#include "main.h"

/**
 * clear_bit - set the value of a bit to 0 at a given index
 * @n: pointer to decimal number to change
 * @index: index position to change
 * Return: 1 if it worked, -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int a;
	unsigned int h;

	if (index > 64)
		return (-1);
	h = index;
	for (a = 1; h > 0; a *= 2, h--)
		;

	if ((*n >> index) & 1)
		*n -= a;

	return (1);
}
