#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number whose bit value is to be retrieved.
 * @index: The index of the bit to be retrieved, starting from 0 (LSB).
 *
 * Return: The value of the bit at the given index (0 or 1), or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);  /* Return -1 if index is out of range */

	unsigned long int mask = 1UL << index; /* Create a mask with 1 at the given index */
	int bit_value = (n & mask) ? 1 : 0; /* Use bitwise AND to extract the bit value */

	return (bit_value);
}

