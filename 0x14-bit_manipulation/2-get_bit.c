#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The unsigned long int number.
 * @index: The index of the bit to retrieve, starting from 0.
 *
 * Return: The value of the bit at the given index, or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1); /* Error: index out of range */

	unsigned long int mask = 1UL << index; /* Create a mask with only the bit at the given index set to 1 */
	int bit_value = (n & mask) ? 1 : 0; /* Retrieve the value of the bit at the given index */

	return (bit_value);
}

