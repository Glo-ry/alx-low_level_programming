#include "main.h"

/**
 * get_bit - a function that returns the value of a bit at a given number
 * @n: the number
 * @index: bit index
 *
 * Return: bit value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	unsigned long int mask = 1;

	mask <<= index;
	unsigned long int bit = n & mask;

	if (bit == mask)
		return (1);
	return (0);
}
