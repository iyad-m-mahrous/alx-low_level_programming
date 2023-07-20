#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_strings - prints strings, followed by a new line
 * @separator: String to be printed between strings
 * @n: number of variadic arguments
 * @...: Arguments Variadic
 *
 * Return: Nothing
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list args;
	char *str;

	if (!separator)
		separator = "";
	if (!n)
	{
		printf("\n");
		return;
	}

	va_start(args, n);
	for (i = 0; i < n - 1; i++)
	{
		str = va_arg(args, char *);
		if (str)
			printf("%s%s", str, separator);
		else
			printf("(nil)%s", separator);
	}
	str = va_arg(args, char *);
	if (str)
		printf("%s\n", str);
	else
		printf("(nil)\n");

	va_end(args);
}
