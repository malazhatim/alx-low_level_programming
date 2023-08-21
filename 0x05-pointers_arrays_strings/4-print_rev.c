#include "main.h"
#include "2-strlen.c"
/**
 * print_rev - reverse a string
 *
 * @s: string to print
 */
void print_rev(char *s)
{
	int i;

	for (a = _strlen(s) - 1; a >= 0; a--)
	{
		_putchar(*(s + a));
	}
	_putchar('\n');
}
