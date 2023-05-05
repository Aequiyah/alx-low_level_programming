#include "main.h"

/**
 * flip_bits - Returns the number of bits needed to flip to get from one number to another
 * @n: The first number
 * @m: The second number
 *
 * Return: The number of bits needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;
	unsigned long int xor_result = n ^ m;

	while (xor_result)
	{
		/* If the least significant bit is set, increment count */
		if (xor_result & 1)
			count++;

		/* Shift right to check the next bit */
		xor_result >>= 1;
	}

	return (count);
}

