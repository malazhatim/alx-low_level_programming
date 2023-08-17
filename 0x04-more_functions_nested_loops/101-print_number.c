#include "main.h"

/**
 * print_number - prints number
 *
 * @n: integer to print to character
 */
void print_number(int n)
{
	int a;
	int b = 1;
	unsigned int x = n;
	unsigned int y = n;
	int c = 0;

	if (n == 0)
	{
		_putchar('0');
	}
	if (n < 0)
	{
		_putchar('-');
		n = n + 1;
		n = -n;
		y = n;
		x = n;
		x += 1;
		y += 1;
	}

	while (x != 0)
	{
		x = x / 10;
		c++;
	}
	for (a = 1; a < c; a++)
	{
		b *= 10;
	}
	for (a = 0; a < c; a++)
	{
		_putchar(y / b + '0');
		y = y % b;
		b = b / 10;
	}
}
