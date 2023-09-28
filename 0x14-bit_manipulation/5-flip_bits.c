#include "main.h"

/**
* flip_bits - Number of bits needed to flip to get from one number to other.
* @n: Number to be fliped to.
* @m: Number to be fliped to.
* Return: Number of bits needed to flip.
**/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int a, b = 0;

	a = n ^ m;
	while (a > 0)
	{
		b += a & 1;
		a >>= 1;
	}
	return (b);
}
