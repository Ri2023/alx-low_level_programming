/*
 * File: 103-find_loop.c
 * Auth: Victoria E Iria
 * A function that finds the loop in a linked list.
 */

#include "lists.h"

/**
 * find_listint_loop - Finds the loop contained in
 *                     a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: If there is no loop - NULL.
 *       else - the address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_p, *fast_p;

	if (head == NULL || head->next == NULL)
		return (NULL);

	slow_p = head->next;
	fast_p = (head->next)->next;

	while (fast_p)
	{
		if (slow_p == fast_p)
		{
			slow_p = head;

			while (slow_p != fast_p)
			{
				slow_p = slow_p->next;
				fast_p = fast_p->next;
			}

			return (slow_p);
		}

		slow_p = slow_p->next;
		fast_p = (fast_p->next)->next;
	}

	return (NULL);
}
