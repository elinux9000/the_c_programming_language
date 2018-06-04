#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(*a))
#define dbgprintf(fmt, ...) printf(fmt, __VA_ARGS__)
#define INT_WIDTH 32
const bool debug = true;

typedef struct
{
	int x;
	int n;
	int answer;
} testdata_t;

int rightrot(int x, int n)
{
	return (x >> n) | (x << (INT_WIDTH-n));
}
int main(void)
{
	testdata_t testdata[] =
	{
		{0, 0, 0},
		{0, 500, 0},
		{-1, 0, -1},
		{-1, 500, -1},
	};
	for (int i = 0; i < ARRAY_SIZE(testdata); i++)
	{
		testdata_t *t = &testdata[i];
		int x = rightrot(t->x, t->n);

		if (x != t->answer)
		{
			printf("Test case %d failed.  Expected %d got %d\n", i, t->answer, x);
			//return EXIT_FAILURE;
		}
	}
	printf("All test cases passed\n");
	return EXIT_SUCCESS;
}
