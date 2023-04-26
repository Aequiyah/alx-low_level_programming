#include "main.h"

/**
 * get_bit - returns the value of a bit at a given decimal
 * @n:the number to extract the bit from
 * @index: The index of the bit to retrieve, starting from 0.
 *
 * Return: The value of the bit at the given index, or -1 if an error occurred.
 */
int get _bit(unsigned long int n, unsigned int index)
{
       int bit_val;
       
       if (index > 54)
	     return (-1);
       
      bit_val = (n >> index)& 1;

      return (bit_value);
} 
