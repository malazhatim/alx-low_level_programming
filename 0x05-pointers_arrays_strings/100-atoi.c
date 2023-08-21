#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int a, d, n, b, f, c;

	a = 0;
	d = 0;
	n = 0;
	b = 0;
	f = 0;
	c = 0;

	while (s[b] != '\0')
		b++;

	while (a < b && f == 0)
	{
		if (s[a] == '-')
			++d;

		if (s[a] >= '0' && s[a] <= '9')
		{
			c = s[a] - '0';
			if (d % 2)
				c = -c;
			n = n * 10 + c;
			f = 1;
			if (s[a + 1] < '0' || s[a + 1] > '9')
				break;
			f = 0;
		}
		a++;
	}

	if (f == 0)
		return (0);

	return (n);
}
