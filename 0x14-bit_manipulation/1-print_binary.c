#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: parameter
 */
void print_binary(unsigned long int n)
{
	int a = 0;
	unsigned long int b = n;

	while (b)
	{
		b = b >> 1;
		a++;
	}

	if (!a)
		putchar('0');

	while (a)
	{
		b = n >> --a;
		if (b & 1)
			putchar('1');
		else
			putchar('0');
	}
}
