#include <stdio.h>
#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 * @n: The number to print in binary
 */
void print_binary(unsigned long int n)
{
    /* Define a mask, starting with 1 shifted to the left */
    unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
    int flag = 0; /* Flag to indicate when non-zero bit found */

    /* Iterate over the bits of the number */
    while (mask > 0)
    {
        /* If the current bit is set in n, print 1 */
        if (n & mask)
        {
            _putchar('1');
            flag = 1; /* Set the flag */
        }
        /* If the flag is set, or the current bit is non-zero, print 0 */
        else if (flag || mask == 1)
            _putchar('0');
        /* Shift the mask to the right */
        mask >>= 1;
    }
}

