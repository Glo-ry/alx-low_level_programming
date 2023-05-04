#include "main.h"

/**
 * flip_bits - a function that returns the number of bits you would need
 * to flip to get from one number to another.
 * @n: the first number
 * @m: the second number
 *
 * Return: number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int g, number_of_bits = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (g = 63; g >= 0; g--)
	{
		current = exclusive >> g;
		if (current & 1)
			number_of_bits++;
	}

	return (number_of_bits);
}
