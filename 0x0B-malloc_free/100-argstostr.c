#include "main.h"
#include <stdlib.h>
/**
  *argstostr - concatenates all arguments of the program.
  *@ac: argument count.
  *@av: pointer to array of size ac.
  *Return: NULL if ac == 0 or av == null, Pointer to new string.
  *NULL on fail.
  */
char *argstostr(int ac, char **av)
{
	int a, b, c, s;
	char *g;

	s = 0;
	c = 0;
	if (ac == 0 || av == NULL)
		return (NULL);
	a = 0;
	while (a < ac)
	{
		b = 0;
		while (av[a][b])
		{
			s++;
			b++;
		}
		s++;
		a++;
	}
	g = malloc((sizeof(char) * s) + 1);
	if (g == NULL)
		return (NULL);
	a = 0;
	while (a < ac)
	{
		b = 0;
		while (av[a][b])
		{
			g[c] = av[a][b];
			b++;
			c++;
		}
		g[c] = '\n';
		c++;
		a++;
	}
	g[c] = '\0';
	return (g);
}
