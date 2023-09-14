#include "variadic_functions.h"

/**
 * print_strings - prints strings
 * @separator: separator between strings
 * @n: number of arguments
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int a;
	char *s;

	va_list list;

	va_start(list, n);

	for (a = 0; a < n; a++)
	{
		s = va_arg(list, char *);
		if (!s)
			s = "(nil)";
		if (!separator)
			printf("%s", s);
		else if (separator && a == 0)
			printf("%s", s);
		else
			printf("%s%s", separator, s);
	}

	printf("\n");

	va_end(list);
}
