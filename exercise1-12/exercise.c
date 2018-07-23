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
 * Exercise 1-12
 * Write a program that prints its input one word per line
 */

#define dbg_printf(...)	{ do { if (debug) printf(__VA_ARGS__); } while (0); }

/* the terminal in non canonical mode sends 4 when ctrl-d
 * is pressed
 * stty -icanon -echo
 */
#define EOT 4

const bool debug;

int main(void)
{
	int c;

	printf("This program will print its input one word per line\n");
	while ((c = getchar()) != EOF && c != EOT)
	{
		dbg_printf(" c=%d\n", c);
		if (c == '\t' || c == ' ')
		{
			putchar('\n');
		}
		else
		{
			putchar(c);
		}
	}
	return EXIT_SUCCESS;
}

