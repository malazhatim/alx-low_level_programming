#include "main.h"

/**
  * rev_string - reverse a string.
  * @s: string to reverse
  */
void rev_string(char *s)
{
	char a;
	int i, j, n;

	j = 0;
	n = 0;

	while (s[j] != '\0')
	{
		j++;
	}

	n = j - 1;

	for (i = 0; i < j / 2; i++)
	{
		a = s[i];
		s[i] = s[n];
		s[n--] = a;
	}
}
