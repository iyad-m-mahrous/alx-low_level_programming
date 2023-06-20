#include <stdio.h>
#define SPLITTER 10000000000000000000UL

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
	unsigned long first1 = 0, first2 = 1,
		      sec1 = 0, sec2 = 2, result1, result2,
		      fhalf1, shalf1, fhalf2, shalf2;

	printf("1, 2");
	for (i = 3; i <= 98; i++)
	{
		fhalf1 = first1 % SPLITTER;
		shalf1 = first2 % SPLITTER;
		fhalf2 = sec1 % SPLITTER;
		shalf2 = sec2 % SPLITTER;
		result1 = fhalf1 + fhalf2 + (shalf1 + shalf2) / SPLITTER;
		result2 = (shalf1 + shalf2) % SPLITTER;
		printf(", %lu%lu", result1, result2);
		first1 = sec1;
		first2 = sec2;
		sec1 = result1;
		sec2 = result2;
	}
	printf("\n");
	return (0);
}
