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
    unsigned long int xor_result = n ^ m;
    unsigned int count = 0;

    /* Count the number of set bits in xor_result */
    while (xor_result != 0)
    {
        /* Increment count if the least significant bit is set */
        count += xor_result & 1;
        /* Shift xor_result to the right */
        xor_result >>= 1;
    }

    return count;
}

