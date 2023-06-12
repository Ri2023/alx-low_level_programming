/*
 * File: 8-sum_listint.c
 * Auth: Victoria E Iria
 * a function that returns the sum of all the data (n)
 *of a listint_t linked list.
 */

#include "lists.h"

/**
 * sum_listint - sum up the value of all data (n) of a listint_t
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: Sum (INT) else 0 if empty.
 */

int sum_listint(listint_t *head)
{
	listint_t *caret = head;
	size_t sum = 0;

	while (caret != NULL)
	{
		sum += caret->n;
		caret = caret->next;
	}
	return (sum);
}
