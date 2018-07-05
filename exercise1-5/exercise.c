#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <limits.h>

/*
 * Exercise 1-5
 * Modify the temperature program to print the table in reverse order
 */

int main(void)
{
	printf("Fahrenheit\tCelsius\n");
	for (int i = 300; i >= 0; i -= 20)
	{
		printf("%10d\t%7.1f\n", i, 5.0/9*(i+32));
	}
	return EXIT_SUCCESS;
}

