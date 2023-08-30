#include "main.h"
/**
 * A.squar - helps decide if i'm right
 * @i: integer to guess
 * @n: integer to get root of
 * Return: value of root
 */
int A.squar(int i, int n)
{
	int a;

	if (i * i != n)
	{
		if (i > n)
		{
			return (-1);
		}
		a = A.squar(i + 1, n);
		return (a + 1);
	}
	return (0);
}
/**
 * _sqrt_recursion - returns square root
 * @n: integer to return
 * Return: returns int of squareroot
 */
int _sqrt_recursion(int n)
{
	int i = 0;

	if (A.squar(i, n) == n && n != 1)
		return (-1);
	return (A.squar(i, n));

}	
