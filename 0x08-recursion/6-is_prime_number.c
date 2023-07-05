#include "main.h"

/**
 * check_prime - checks if a number is prime
 * @n: Number Integer
 * @b: all numbers down to 1
 *
 * Return: On prime return 1 else 0
 */

int check_prime(int n, int b)
{
	if (n < 2)
		return (0);
	if (n % b == 0 && b != 1)
		return (0);
	if (b == 1)
		return (1);
	check_prime(n, b - 1);
}

/**
 * is_prime_number - checks if a number is prime
 * @n: Number Integer
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int is_prime_number(int n)
{
	return (check_prime(n, n - 1));
}
