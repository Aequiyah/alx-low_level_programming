#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if there is one or more chars in the
 * string b that is not 0 or 1, or if b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	unsigned int bit;
	const char *c;

	if (b == NULL)
		return (0);

	for (c = b; *c != '\0'; c++)
	{
		if (*c != '0' && *c != '1')
			return (0);
	}

	for (bit = 1, c--; c >= b; c--, bit *= 2)
	{
		if (*c == '1')
			result += bit;
	}

	return (result);
}

