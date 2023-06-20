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
	int i;

	printf("1, 2");
	for (i = 3; i <= 50; i++)
		printf(", %d", fib(i));
	printf("\n");
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
	return (fib(n - 1) + fib(n - 2));
}
