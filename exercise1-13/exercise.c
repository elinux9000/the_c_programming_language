#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <limits.h>
#include <termios.h>
#include <unistd.h>


#define dbg_printf(...)	{ do { if (debug) printf(__VA_ARGS__); } while (0); }

/*
 * Exercise 1-13
 * Write a program that prints a vertical histogram of the lengths of words in
 * its input.
 */


/* the terminal in non canonical mode sends 4 when ctrl-d
 * is pressed
 * stty -icanon -echo
 */
#define EOT 4

const bool debug;
int get_words(int h[])
{
	int c;
	int len = 0;
	int size = 0;
	char state = 0; //0 = out of word, 1 = in word

	while (true)
	{
		c = getchar();
		if (isspace(c) || c == EOF || c == EOT)
		{
			if (state == 1)
			{
				h[len]++;
				if (size < len)
					size = len;
				dbg_printf(" h[%d]=%d size=%d\n",
				len, h[len], size);
				len = 0;
				state = 0;
			}
		}
		else
		{
			state = 1;
			len++;
			dbg_printf(" len=%d\n", len);
		}
		if (c == EOF || c == EOT)
			break;
		putchar(c);
	}
	return size;
}
void print_h_histo(int h[], int size)
{
	printf("Horizontal histogram\n");
	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j < h[i];  j++)
			putchar('*');
		putchar('\n');
	}
}
int find_max(int h[], int size)
{
	int max = h[0];

	for (int i = 0; i < size; i++)
		max = max > h[i] ? max:h[i];
	return max;
}
void print_v_histo(int h[], int size)
{
	int max = find_max(h, size);

	dbg_printf("Max=%d\n", max);
	printf("Vertical histogram\n");
	for (int i = max; i > 0 ; i--)
	{
		for (int j = 1; j <= size; j++)
		{
			if (h[j] >= max)
				putchar('*');
			else
				putchar(' ');
		}
		max--;
		putchar('\n');
	}
}
int main(void)
{
	int size;
	int h[1024] = {0};

	printf("This program will print a histogram of the length of words\n");
	size = get_words(h);
	print_h_histo(h, size);
	print_v_histo(h, size);
	return EXIT_SUCCESS;
}
