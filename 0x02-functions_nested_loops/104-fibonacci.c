#include <stdio.h>
#include <stdint.h>

/**
 * main - Entry Function
 *
 * Description: Task 16
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int i;
	uint64_t first = 1, sec = 2, result;

	printf("1, 2");
	for (i = 3; i <= 98; i++)
	{
		result = first + sec;
		printf(", %lu", result);
		first = sec;
		sec = result;
	}
	printf("\n");
	return (0);
}
