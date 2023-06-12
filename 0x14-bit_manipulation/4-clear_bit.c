/*
 * File: 4-clear_bit.c
 * Auth: Victoria E Iria
 * A function that sets the value of a bit to 0 at a given index.
 */

#include <stdio.h>
#include "main.h"

/**
 * clear_bit - This function sets the value of a bit at a given index to 0.
 * @n: A pointer to the number to be used.
 * @index: The position to set the value at - indices start at 0.
 *
 * Return: If an error occurs -1.
 *         else, 1 on succes.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 65)
		return (-1);

	if ((*n >> index) & 1)
	{
		*n -= 1 << index;
		return (1);
	}
	else
		return (1);
}


