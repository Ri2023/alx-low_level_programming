/*
 * File: 5-flip_bits.c
 * Auth: Victoria E Iria
 * A function that returns the number of bits you would
 *      need to flip to get from one number to another.
 */

#include <stdio.h>
#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to be
 *             flipped to get from n - m.
 * @n: The number it started with
 * @m: The number n is flipped to.
 *
 * Return: The  number of bits that was flipped.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m, flipped_bits = 0;

	do {
	flipped_bits += (xor & 1);
	xor >>= 1;
	} while (xor > 0);

	return (flipped_bits);
}
