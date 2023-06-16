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
	} while (a <= 'z');

	putchar('\n');

	return (0);
}
