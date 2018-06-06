#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const bool debug;
#define dbg_printf(fmt, ...)	do\
				{\
					if (debug)\
						printf(fmt, __VAR_ARGS__);\
				} \
				while (0)
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(*arr))
/*
 * Write a binary search with only one test inside the loop
 */
int binsearch(int x, int v[], int n)
{
	int low = 0;
	int high = n-1;
	int mid = (low + high)/2;

	while (low <= high &&  v[mid] != x )
	{
		if (x > v[mid])
			low = mid+1;
		else
			high = mid-1;
		mid = (low + high) / 2;
	}
	if (v[mid] == x)
		return mid;
	return -1;
}
int main(void)
{
	int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i = -1; i < (int)(ARRAY_SIZE(v)+1); i++)
	{
		printf("Index of %d = %d\n", i, binsearch(i, v, ARRAY_SIZE(v)));
	}
}
