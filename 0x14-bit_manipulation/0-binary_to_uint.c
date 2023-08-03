#include <main.h>

/**
 * binary_to_uint - converts a bit string to unsigned int
 *
 * @b: string to convert
 *
 * Return: decimal unsigned int value
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (!b)
		return (0);

	while (*b != '\0')
	{
		if (*b == '0')
		{
			result = result << 1;
		}
		else if (*b == '1')
		{
			result = result << 1;
			result++;
		}
		else
		{
			return (0);
		}
		b++;
	}
	return (result);
}
