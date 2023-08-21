#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - program that generates random valid
 * passwords for the program 101-crackme
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int a[100];
	int i, j, n;

	j = 0;	

	srand(time(NULL));

	for (i = 0; i < 100; i++)
	{
		a[i] = rand() % 78;
		j += (a[i] + '0');
		putchar(a[i] + '0');
		if ((2772 - j) - '0' < 78)
		{
			n = 2772 - j - '0';
			j += n;
			putchar(n + '0');
			break;
		}
	}

	return (0);
}
