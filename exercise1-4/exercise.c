#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <limits.h>

/*
 * Exercise 1-4
 * Write a program to print the corresponding Celsius to Fahrenheit table
 */

int main(void)
{
	printf("Celsius\tFahrenheit\n");
	for (int i = -40; i <= 200; i += 20)
	{
		printf("%7d\t%10.1f\n", i, 9.0/5*i+32);
	}
	return EXIT_SUCCESS;
}

