#include "main.h"

/**
 * _atoi - Convert a string to an integer.
 * @s: The pointer to convert
 *
 * Return: A integer
 */
int _atoi(char *s)
{
	int num = 0, sign = 1, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (i > 0)
				if (s[i - 1] == '-')
					sign = -1;
			num = (num * 10) + (s[i] - '0');
		}
		else if (num != 0)
		{
			break;
		}
	}

	return (num * sign);
}
