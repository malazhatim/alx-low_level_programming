#include "main.h"

/**
  * rev_string - reverse a string.
  * @s: string to reverse
  */
void rev_string(char *s)
{
	int a, b;
	int c = 0;

	while (*(s + c) != '\0')
	{
		c++;
	}

	c = 1;
	a = 0;
	while (c >a)
	{
		b = s[a];
		s[a] = s[c];
		s[c] = b;
		b++;
		c--;
	}

}


