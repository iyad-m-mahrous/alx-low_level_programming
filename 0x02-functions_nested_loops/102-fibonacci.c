#include <stdio.h>

/**
 * main - Entry Function
 *
 * Description: Task 14
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int i, first = 1, sec = 2, result;

	printf("1, 2");
	for (i = 3; i <= 50; i++)
	{
		result = first + sec;
		printf(", %d", result);
		first = sec;
		sec = result;
	}
	printf("\n");
	return (0);
}
