#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index
 * @n: The number to extract the bit from
 * @index: The index of the bit to retrieve, starting from 0.
 *
 * Return: The value of the bit at the given index, or -1 if an error occurred.
 * */
int get _bit(unsigned long int n, unsigned int index)
{
       int bit_value;
       
       if (index > 63)
	     return (-1);
       
      bit_value = (n >> index)& 1;

      return  (bit_value);
} 
