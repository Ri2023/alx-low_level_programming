/*
 * File: 3-set_bit.c
 * Auth: Victoria E Iria
 * A function that sets the value of a bit to 1 at a given index.
 */

#include <stdio.h>
#include "main.h"

/**
 * set_bit - This Function  sets the value of a bit at a given index to 1.
 * @n: A pointer to the bit.
 * @index: The index to set the value at - indices start at 0.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 1.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 65)
		return (-1);

	if (!((*n >> index) & 1))
	{
		*n += 1 << index;
		return (1);
	}
	else
		return (-1);
}

