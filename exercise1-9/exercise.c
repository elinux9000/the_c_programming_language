#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <limits.h>
#include <termios.h>
#include <unistd.h>


/*
 * Exercise 1-9
 * Write a program to copy its input to its output, replacing each string of
 * one or more blanks by a single blank.
 */
#define dbg_printf(...) do { if (debug) printf(__VA_ARGS__); } while (0)

/* the terminal in non canonical mode sends 4 when ctrl-d
 * is pressed
 */
#define EOT 4

const bool debug;

int main(void)
{
	int c;
	int previous = EOF;

	printf("This program will remove sequential spaces from the input\n");
	while ((c = getchar()) != EOF && c != EOT)
	{
		if (c != ' ' || previous != ' ')
		{
			putchar(c);
		}
		previous = c;
	}
	return EXIT_SUCCESS;
}

