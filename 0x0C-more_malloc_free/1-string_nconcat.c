#include <stdlib.h>
#include "main.h"

/**
 * *string_nconcat - concatenates n bytes of a string to another string
 * @s1: string to append to
 * @s2: string to concatenate from
 * @n: number of bytes from s2 to concatenate to s1
 *
 * Return: pointer to the resulting string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *a;
	unsigned int b = 0, c = 0, d = 0, e = 0;

	while (s1 && s1[d])
		d++;
	while (s2 && s2[e])
		e++;

	if (n < e)
		a = malloc(sizeof(char) * (d + n + 1));
	else
		a = malloc(sizeof(char) * (d + e + 1));

	if (!a)
		return (NULL);

	while (b < d)
	{
		a[b] = s1[b];
		b++;
	}

	while (n < e && b < (d + n))
		a[b++] = s2[c++];

	while (n >= e && b < (d + e))
		a[b++] = s2[c++];

	a[b] = '\0';

	return (a);
}
