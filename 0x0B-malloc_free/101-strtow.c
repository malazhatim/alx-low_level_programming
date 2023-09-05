#include <stdlib.h>
#include "main.h"

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int f, a, b;

	f = 0;
	b = 0;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (s[a] == ' ')
			f = 0;
		else if (f == 0)
		{
			f = 1;
			b++;
		}
	}

	return (b);
}
/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **m, *t;
	int c, d = 0, l = 0, w, n = 0, sta, end;

	while (*(str + l))
		l++;
	w = count_w(str);
	if (w == 0)
		return (NULL);

	m = (char **) malloc(sizeof(char *) * (w + 1));
	if (m == NULL)
		return (NULL);

	for (c = 0; c <= l; c++)
	{
		if (str[c] == ' ' || str[c] == '\0')
		{
			if (n)
			{
				end = c;
				t = (char *) malloc(sizeof(char) * (n + 1));
				if (t == NULL)
					return (NULL);
				while (sta < end)
					*t++ = str[sta++];
				*t = '\0';
				m[d] = t - n;
				d++;
				n = 0;
			}
		}
		else if (n++ == 0)
			sta = c;
	}

	m[d] = NULL;

	return (m);
}
