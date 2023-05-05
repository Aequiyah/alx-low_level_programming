#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index
 * @n: Pointer to the unsigned long integer whose bit needs to be set
 * @index: Index of the bit to be set, starting from 0
 *
 * Return: 1 if successful, -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	/* Check if index is out of range for unsigned long int */
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	/* Set the bit to 1 using bitwise OR operation */
	*n |= (1ul << index);

	return (1);
}

