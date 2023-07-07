#include "main.h"

/**
  * puts2 - Prints every other character of a string
  * @str: The string to be treated
  *
  * Return: void
  */
void puts2(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!(i % 2))
			_putchar(str[i]);
	}

	_putchar('\n');
}
