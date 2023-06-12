/*
 * File: 2-get_bit.c
 * Auth: Victoria E Iria
 * A function that returns the value of a bit at a given index.
 */

#include <stdio.h>
#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index.
 * @n: The bit.
 * @index: The index to get the value at - indices start at 0.
 *
 * Return: the converted value
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index > sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	else if (index == 0)
	{
		return (n & 1);
	}
	else
	{
		return (get_bit(n >> 1, index - 1));
	}
}
