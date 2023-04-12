#include "main.h"


/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print in binary.
 *
 * Return: None.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int printed = 0;

	while (mask > 0)
	{
		if ((n & mask) == mask)
		{
			_putchar('1');
			printed = 1;
		}
		else if (printed)
			_putchar('0');
		mask >>= 1;
	}
	if (!printed)
		_putchar('0');
}

