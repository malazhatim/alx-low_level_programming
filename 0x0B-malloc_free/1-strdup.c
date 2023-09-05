#include <stdlib.h>
#include "main.h"

/**
 * *_strdup - copies the string given as parameter
 * @str: string to duplicate
 *
 * Return: pointer to the copied string (Success), NULL (Error)
 */
char *_strdup(char *str)
{
	char *d;
	unsigned int a, b;

	a = 0;
	b = 0;

	if (str == NULL)
		return (NULL);

	while (str[b])
		b++;

	d = malloc(sizeof(char) * (b + 1));

	if (d == NULL)
		return (NULL);

	while ((d[a] = str[a]) != '\0')
		a++;

	return (d);
}
