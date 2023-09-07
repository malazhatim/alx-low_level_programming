#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * is_digit - checks if a string contains a non-digit char
 * @s: string to be evaluated
 *
 * Return: 0 if a non-digit is found, 1 otherwise
 */
int is_digit(char *s)
{
	int a = 0;

	while (s[a])
	{
		if (s[a] < '0' || s[a] > '9')
			return (0);
		a++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int b = 0;

	while (s[b] != '\0')
	{
		b++;
	}
	return (b);
}

/**
 * errors - handles errors for main
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *c1, *c2;
	int l1, l2, l, d, ca, dig1, dig2, *res, e = 0;

	c1 = argv[1], c2 = argv[2];
	if (argc != 3 || !is_digit(c1) || !is_digit(c2))
		errors();
	l1 = _strlen(c1);
	l2 = _strlen(c2);
	l = l1 + l2 + 1;
	res = malloc(sizeof(int) * l);
	if (!res)
		return (1);
	for (d = 0; d <= l1 + l2; d++)
		res[d] = 0;
	for (l1 = l1 - 1; l1 >= 0; l1--)
	{
		dig1 = c1[l1] - '0';
		ca = 0;
		for (l2 = _strlen(c2) - 1; l2 >= 0; l2--)
		{
			dig2 = c2[l2] - '0';
			ca += res[l1 + l2 + 1] + (dig1 * dig2);
			res[l1 + l2 + 1] = ca % 10;
			ca /= 10;
		}
		if (ca > 0)
			res[l1 + l2 + 1] += ca;
	}
	for (d = 0; d < l - 1; d++)
	{
		if (res[d])
			e = 1;
		if (e)
			_putchar(res[d] + '0');
	}
	if (!e)
		_putchar('0');
	_putchar('\n');
	free(res);
	return (0);
}
