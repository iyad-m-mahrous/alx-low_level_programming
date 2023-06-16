#include <stdio.h>
/**
 * main - Entry Function
 *
 * Description: Task 5
 *
 * Return: 0 (Success)
 */

int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
		putchar((int) '0' + i);
	putchar('\n');

	return (0);
}
