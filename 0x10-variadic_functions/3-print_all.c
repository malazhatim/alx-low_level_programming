#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	int a = 0;
	char *s1, *s2 = "";

	va_list list;

	va_start(list, format);

	if (format)
	{
		while (format[a])
		{
			switch (format[a])
			{
				case 'c':
					printf("%s%c", s2, va_arg(list, int));
					break;
				case 'i':
					printf("%s%d", s2, va_arg(list, int));
					break;
				case 'f':
					printf("%s%f", s2, va_arg(list, double));
					break;
				case 's':
					s1 = va_arg(list, char *);
					if (!s1)
						s1 = "(nil)";
					printf("%s%s", s2, s1);
					break;
				default:
					a++;
					continue;
			}
			s2 = ", ";
			a++;
		}
	}

	printf("\n");
	va_end(list);
}
