/*
 * File: 0-print_listint.c
 * Auth: Victoria E Iria
 * A programme that prints all the elements of a listint_t list.
 */

#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: head of the list_t list.
 *
 * Return: The number of nodes in the list_t list.
 */

size_t print_listint(const listint_t *h)
{
	const listint_t *caret = h;
	size_t num = 0;

	while (caret != NULL)
	{
		printf("%d\n", caret->n);
		num += 1;
		caret = caret->next;
	}
	return (num);
}
