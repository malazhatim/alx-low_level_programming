#include "main.h"
/**
 * _puts - puts a string
 *
 * @str: string to print
 */
void _puts(char *str)
{
	int a;

	for (a = 0; *(str + a) != '\0'; a++)
	{
		_putchar(*(str + a));
	}
	_putchar('\n');
}
