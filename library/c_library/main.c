#include <stdint.h>
#include <stdio.h>
#include "david_sum.h"

int main()
{
	uint8_t n1, n2, x;

	n1 = 5;
	n2 = 7;

	x = david_sum(n1, n2);

	printf("The sum of %d and %d is %d\n", n1, n2, x);

	return 0;
}