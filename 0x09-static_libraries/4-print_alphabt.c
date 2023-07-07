#include <stdio.h>
/**
 * main - Entry Function
 *
 * Description: Task 4
 *
 * Return: 0 (Success)
 */

int main(void)
{
	char a = 'a';

	do {
		if (a != 'q' && a != 'e')
			putchar(a++);
		else
			a++;
	} while (a <= 'z');

	putchar('\n');

	return (0);
}
