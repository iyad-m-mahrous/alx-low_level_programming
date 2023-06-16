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
	char a = 'a';

	do {
		putchar(a++);
		if (a == ('z' + 1))
			a = 'A';
	} while (a != ('Z' + 1));

	putchar('\n');

	return (0);
}
