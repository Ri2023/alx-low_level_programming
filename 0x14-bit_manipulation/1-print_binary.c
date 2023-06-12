/*
 * File: 1-print_binary.c
 * Auth:Victoria E Iria
 * A function that prints the binary representation of a number.
 */

#include <stdio.h>
#include "main.h"

/**
 * print_binary - A function prints the binary representaion of a number
 * @n: number to be used for binary representation
 *
 * Return: void
 */

void print_binary(unsigned long int n)
{
	if (n >> 1 == 0)
	{
		_putchar((n & 1) + '0');
	}
	else
	{
		print_binary(n >> 1);
		_putchar((n & 1) + '0');
	}
}
