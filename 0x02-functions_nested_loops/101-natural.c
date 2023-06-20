#include <stdio.h>
/**
 * main - Entry Function
 * @n: the number to be used
 *
 * Description: Task 13
 *
 * Return: 0 (Success)
 */

int main(int n)
{
	int i, sum = 0;

	for (i = 0; i < n; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}
	printf("%d\n", sum);
	return (0);
}
