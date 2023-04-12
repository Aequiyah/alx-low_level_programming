#include "main.h"

/**
 * get_endianness - Function to check the endianness of the system
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *ptr = (char *)&num;

	if (*ptr == 1)
		return 1; // Little Endian
	else
		return 0; // Big Endian
}

