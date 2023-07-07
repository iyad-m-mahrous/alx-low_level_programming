#include <stdio.h>

/**
 * main - Entry Function
 *
 * Description: Task 15
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int i;
	long int first = 1, sec = 2, result, evensum = 2;

	for (i = 3; i <= 50; i++)
	{
		result = first + sec;
		if (result > 4000000)
			break;
		if (result % 2 == 0)
			evensum += result;
		first = sec;
		sec = result;
	}
	printf("%ld\n", evensum);
	return (0);
}
