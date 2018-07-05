#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <limits.h>

/*
 * Exercise 1-3
 * Modify the temperature conversion program to print a heading above the
 * table.
 */

int main(void)
{
	printf("Fahrenheit\tCelsius\n");
	for (int i = 0; i <= 300; i += 20)
	{
		printf("%10d\t%7.1f\n", i, 5.0/9*(i-32));
	}
	return EXIT_SUCCESS;
}

