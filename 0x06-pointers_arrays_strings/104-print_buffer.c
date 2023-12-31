#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer
 * @b: buffer.
 * @size: size of buffer.
 * Return: no return.
 */
void print_buffer(char *b, int size)
{
	int i, j, k, l = 0;
	char *b1 = b, *b2 = b, *b3 = b;

	(size <= 0) ? printf("\n") : l++;
	if (size <= 0)
		return;
	for (i = 0; i < ((size / 10) + (size % 10 ? 1 : 0)); i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (j == 0)
				printf("%08lx:", (unsigned long)(b1 - b));
			else if (j == 11)
			{
				for (k = 0; k < 10; k++)
				{
					if (b2 - b < size)
					{
					if (*b2 != '\\' && *b2 != '\n' && *b2 > 9)
						printf("%c", *b2);
					else
						printf(".");
					b2++;
					}
				}
			}
			else
			{
				if (b3 - b < size)
					printf("%02lx", (unsigned long)*b3);
				else
					printf("  ");
				b3++;
			}
			((j + 1) % 2) ? printf(" ") : l++;
			b1++;
		}
		b1 -= 2;
		printf("\n");
	}
}
