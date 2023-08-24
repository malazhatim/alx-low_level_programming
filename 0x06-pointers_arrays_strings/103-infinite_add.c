#include "main.h"

/**
 * rev_string - reverse array
 * @n: integer params
 * Return: 0
 */

void rev_string(char *n)
{
	int a = 0;
	int b = 0;
	char c;

	while (*(n + a) != '\0')
	{
		a++;
	}
	a--;

	for (b = 0; b < a; b++, a--)
	{
		c = *(n + b);
		*(n + b) = *(n + a);
		*(n + a) = c;
	}
}

/**
 * infinite_add - add 2 numbers together
 * @n1: text representation of 1st number to add
 * @n2: text representation of 2nd number to add
 * @r: pointer to buffer
 * @size_r: buffer size
 * Return: pointer to calling function
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int of = 0, d = 0, e = 0, dig = 0;
	int v1 = 0, v2 = 0, t = 0;

	while (*(n1 + d) != '\0')
		d++;
	while (*(n2 + e) != '\0')
		e++;
	d--;
	e--;
	if (e >= size_r || d >= size_r)
		return (0);
	while (e >= 0 || d >= 0 || of == 1)
	{
		if (d < 0)
			v1 = 0;
		else
			v1 = *(n1 + d) - '0';
		if (e < 0)
			v2 = 0;
		else
			v2 = *(n2 + e) - '0';
		t = v1 + v2 + of;
		if (t >= 10)
			of = 1;
		else
			of = 0;
		if (dig >= (size_r - 1))
			return (0);
		*(r + dig) = (t % 10) + '0';
		dig++;
		e--;
		d--;
	}
	if (dig == size_r)
		return (0);
	*(r + dig) = '\0';
	rev_string(r);
	return (r);
}
