#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index
 * @n: The number to extract the bit from
 * @index: The index of the bit to get
 *
 * Return: The value of the bit at index index, or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
    /* Ensure index is within bounds */
    if (index >= sizeof(unsigned long int) * 8)
        return (-1);

    /* Shift the number to the right to bring the desired bit to the least significant position */
    n >>= index;

    /* Return the least significant bit, which is now the desired bit */
    return (n & 1);
}

