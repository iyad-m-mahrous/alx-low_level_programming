#include "main.h"
/**
 * main - Entry Function
 *
 * Description: Task 1
 *
 * Return: 0 (Success)
 */

int main(void)
{
	print_alphabet();
	return (0);
}

/**
 * print_alphabet -  prints the lowercase alphabet
 */
void print_alphabet(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
	{
		_putchar(i);
	}
	_putchar('\n');

}
