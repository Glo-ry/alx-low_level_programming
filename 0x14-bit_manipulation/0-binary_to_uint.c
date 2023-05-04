#include "main.h"

/**
 * binary_to_uint - function that converts binary to unsigned integer
 * @b: the string
 *
 * Return: number that has been converted
 */
unsigned int binary_to_uint(const char *b)
{
	if (b == 0)
	{
		return (0);
	}

	unsigned int d_value = 0;
	int g = 0;

	while (b[g] != '\0')
	{
		if (b[g] != '0' && b[g] != '1')
		{
			return (0);
		}

		d_value = (d_value << 1) + (b[g] - '0');
		g++;
	}

	return (d_value);
}
