#include "main.h"

int actual_p(int a, int b);

/**
 * is_prime_number - says if an integer is a prime number or not
 * @n: number to evaluate
 *
 * Return: 1 if n is a prime number, 0 if not
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (actual_p(n, n - 1));
}

/**
 * actual_p - calculates if a number is prime recursively
 * @a: number to evaluate
 * @b: iterator
 *
 * Return: 1 if n is prime, 0 if not
 */
int actual_p(int a, int b)
{
	if (b == 1)
		return (1);
	if (a % b == 0 && b > 0)
		return (0);
	return (actual_p(a, b - 1));
}
