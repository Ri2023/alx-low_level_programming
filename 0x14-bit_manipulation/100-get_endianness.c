/*
 * File: 100-get_endianness.c
 * Auth: Victoria E Iria
 * A function that checks the endianness.
 */

#include <stdio.h>
#include "main.h"

/**
 * get_endianness -A function that Checks the size of endian.
 *
 * Return: 0 If big-endian.
 *         otherwise 1 if little-endian.
 */

int get_endianness(void)
{
	unsigned int fig = 1;
	char *ed = (char *)&fig;

	if (*ed)
		return (1);

	return (0);
}

