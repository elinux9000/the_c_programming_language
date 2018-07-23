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
 * Exercise 1-10
 * Write a program to copy its input to its output, replacing each tab by \t
 * each backspace by \b and each backslash by \\
 * CTRL-H sends the backspace character in gnome-terminal
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

	printf("This program will show tabs, backspaces and backslashes.\n");
	printf("CTRL-h sends the backspace character in gnome-terminal\n");

	while ((c = getchar()) != EOF && c != EOT)
	{
		dbg_printf(" c=%d\n", c);
		if (c == '\t')
		{
			printf("\\t");
		}
		else if (c == '\b')
		{
			printf("\\b");
		}
		else if (c == '\\')
		{
			printf("\\\\");
		}
		else
		{
			putchar(c);
		}
	}
	return EXIT_SUCCESS;
}

