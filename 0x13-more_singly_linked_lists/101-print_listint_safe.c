/*
 * File: 101-print_listint_safe.c
 * Auth: Victoria E Iria
 * A function that prints a listint_t linked list.
 */

#include "lists.h"
#include <stdio.h>

/**
 * looped_listint_len - Counts the number of unique nodes
 *                     in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 * print_listint_safe - Prints a listint_t list safely.
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the list.
 */
i
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *pokey_p = head, *rapid_p = head;
	size_t count = 0;
	int is_loop = 0;

	while (pokey_p && rapid_p && rapid_p->next)
	{
		if (!(rapid_p->next->next))
			break;
		pokey_p = pokey_p->next;
		rapid_p = rapid_p->next->next;
		if (pokey_p == rapid_p)
		{
			pokey_p = pokey_p->next;
			is_loop = 1;
			break;
		}
	}

	if (!is_loop)
	{
		while (head)
		{
			count++;
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		return (count);
	}

	while (head)
	{
		count++;
		if (head == pokey_p)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			printf("-> [%p] %d\n", (void *)head, head->next->n);
			exit(98);
		}

		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	return (0);
}

