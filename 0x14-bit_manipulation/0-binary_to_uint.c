#include "main.h"

/**
 * binary_to_uint - function that converts binary to unsigned integer
 * @b: the string
 *
 * Return: number that has been converted
 */
unsigned int binary_to_uint(const char *b)
{
	int g;
	unsigned int d_value = 0;

	if (!b)
		return (0);

	for (g = 0; b[g]; g++)
	{
		if (b[g] < '0' || b[g] > '1')
			return (0);
		d_value = 2 * d_value + (b[g] - '0');
	}

	return (d_value);
}
