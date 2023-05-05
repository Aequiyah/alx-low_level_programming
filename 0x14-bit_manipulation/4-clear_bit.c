#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index
 * @n: Pointer to the unsigned long int whose bit needs to be cleared
 * @index: The index of the bit to be cleared, starting from 0
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1); /* Return -1 if index is out of bounds */

	*n &= ~(1UL << index); /* Clear the bit at the given index */

	return (1); /* Return 1 indicating success */
}

