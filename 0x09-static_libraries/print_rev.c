#include "main.h"

/**
  * print_rev - Prints a string in reverse
  * @s: The string to print
  *
  * Return: void
  */
void print_rev(char *s)
{
	int len;

	for (len = 0; *(s + len) != '\0' ; len++)
		;

	while (len)
	{
		_putchar(*(s + (--len)));
	}

	_putchar('\n');

}
