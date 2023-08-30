#include "main.h"

/**
 * actual_sqrt_recursion - recurses to find the natural
 * square root of a number
 * @n: number to calculate the sqaure root of
 * @i: iterator
 *
 * Return: the resulting square root
 */
int actual_sqrt_recursion(int n, int i)
{
     int b;

	if (i * i != n)
	{
		if (i > n)
		{
			return (-1);
		}
		b = actual_sqrt_recursion(i + 1, n);
		return (b + 1);
	}
	return (0);
}	
/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to calculate the square root of
 *
 * Return: the resulting square root
 */
int _sqrt_recursion(int n)
{
	int a = 0;

	if (actual_sqrt_recursion(a, n) == n && n != 1)
		return (-1);
	return (actual_sqrt_recursion(a, n));

}	
