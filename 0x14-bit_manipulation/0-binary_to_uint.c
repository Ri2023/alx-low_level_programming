/*
 * Auth: Victoria E Iria
 * File: 0-binary_to_uint.c
 * A function that converts a binary number to an unsigned int.
 */

#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: the binary number as a string/ pointer to the string.
 *
 * Return: The converted numbe.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int dec = 0, base_num = 1;
	int strg_len;

	if (!b || !*b)
		return (0);

	for (strg_len = 0; b[strg_len];)
		strg_len++;

	for (strg_len -= 1; strg_len >= 0; strg_len--)
	{
		if (b[strg_len] != '0' && b[strg_len] != '1')
			return (0);

		dec += (b[strg_len] - '0') * base_num;
		base_num *= 2;
	}

	return (dec);
}
