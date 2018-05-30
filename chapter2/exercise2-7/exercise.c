#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

typedef struct
{
	uint8_t x;
	uint8_t p;
	uint8_t n;
	uint8_t answer;
} test_data_t;

uint8_t invert(uint8_t x, uint8_t p, uint8_t n)
{
	uint8_t mask = 1<<p;

	for (int i = 0; i < n ; i++)
	{
		if (x & mask)
		{
			x = x & ~mask;
		}
		else
		{
			x = x | mask;
		}
		mask <<= 1;
	}
	return x;
}
test_data_t test_data[] =
{
	{0, 0, 8, 0xff},
	{0, 0, 100, 0xff},
	{0xff, 0, 8, 0x0},
	{0xff, 0, 100, 0x0},
	{0xaa, 4, 4, 0x5a},
	{0xaa, 4, 40, 0x5a},
	{0x0f, 0, 4, 0x00},
	{0x01, 0, 40, 0xfe},
};
int main(void)
{
	for (int i = 0; i < ARRAY_SIZE(test_data); i++)
	{
		test_data_t *t = &test_data[i];
		uint8_t a = invert(t->x, t->p, t->n);

		if (a != t->answer)
		{
			printf("test case %d failed.  Expected 0x%X got 0x%X\n"
			, i, t->answer, a);
			return 1;
		}

	}

	printf("All test cases passed\n");
	return 0;
}

