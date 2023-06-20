#include <stdio.h>
int fib(int);

/**
 * main - Entry Function
 *
 * Description: Task 14
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int sum = fib(50);

	printf("%d\n", sum);
	return (0);
}


/**
 * fib - Entry Function
 * @n: The base number
 *
 *
 * Return: fib number
 */
int fib(int n)
{
	if (n == 1 || n == 2)
		return (1);
	return (fib(n) + fib(n - 1));
}
