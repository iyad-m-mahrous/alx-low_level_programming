#include <stdio.h>
/**
 * main - Entry Function
 *
 * Description: Task 2
 *
 * Return: 0 (Success)
 */

int main(void)
{
	char a = 'z';

	do {
		putchar(a--);
	} while (a >= 'a');

	putchar('\n');

	return (0);
}
