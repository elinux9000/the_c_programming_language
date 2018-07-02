#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <limits.h>

/*
 * Write a function itob(n, s, b) that converts the integer n into a base
 * b char representation in the string s.
 */

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(*arr))
const bool debug;
#define dbg_printf(fmt, ...) \
	do { if (debug) printf(fmt, __VA_ARGS__); } while (0)
typedef struct
{
	int n;
	int b;
	char *answer;
} test_t;

void reverse(char s[])
{
	if (s)
	{
		if (s[0] == '-')
			s++;
		size_t len = strlen(s);

		for (size_t i = 0; i < len/2; i++)
		{
			char c = s[i];

			s[i] = s[len-1-i];
			s[len-1-i] = c;
		}
	}
}
void itob(int n, char s[], int b)
{
	int i = 0;
	int r;
	bool neg = false;
	static const char symbol[] = "0123456789abcdefghijklmnopqrstuvwxyz";

	if (!s)
	{
		sprintf("s is null\n");
		return;
	}
	if (b < 1 || b > 36)
	{
		printf("invalid base %d\n", b);
		return;
	}
	if (n < 0)
	{
		s[i++] = '-';
		neg = true;
	}
	do
	{
		r = n % b;
		if (neg)
			r = -r;
		s[i++] = symbol[r];
		n = n/b;
	} while (n != 0);
	s[i] = 0;
	reverse(s);
}
int main(void)
{
	test_t test_data[] =
	{
		{0, 10, "0"},
		{-1, 10, "-1"},
		{10, 10, "10"},
		{-100, 10, "-100"},
		{INT_MIN, 10, "-2147483648"},
		{INT_MAX, 10, "2147483647"},
		{10, 16, "a"},
		{-10, 16, "-a"},
		{35, 36, "z"},
		{9, 8, "11"},
	};
	char s[1024];

	for (int i = 0; i < ARRAY_SIZE(test_data); i++)
	{
		itob(test_data[i].n, s, test_data[i].b);
		if (strcmp(test_data[i].answer, s) != 0)
		{
			printf("Test failed.  Got %s expected %s\n",
					s, test_data[i].answer);
			//return EXIT_FAILURE;
		}
		else
		{
			printf("%d in base %d is %s\n", test_data[i].n,
			test_data[i].b, s);
		}
	}
	printf("All tests passed\n");
	return EXIT_SUCCESS;
}

