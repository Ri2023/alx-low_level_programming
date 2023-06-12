/*
 * File: 102-free_listint_safe.c
 * A function that frees a listint_t list.
 */

#include "lists.h"

size_t looped_listint_count(listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * looped_listint_count - Counts the number of unique nodes
 *                      in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the list.
 */

size_t looped_listint_count(listint_t *head)
{
	listint_t *slow_p, *fast_p;
	size_t n_nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	slow_p = head->next;
	fast_p = (head->next)->next;

	while (fast_p)
	{
		if (slow_p == fast_p)
		{
			slow_p = head;
			while (slow_p != fast_p)
			{
				n_nodes++;
				slow_p = slow_p->next;
				fast_p = fast_p->next;
			}

			slow_p = slow_p->next;
			while (slow_p != fast_p)
			{
				n_nodes++;
				slow_p = slow_p->next;
			}

			return (n_nodes);
		}

		slow_p = slow_p->next;
		fast_p = (fast_p->next)->next;
	}

	return (0);
}

/**
 * free_listint_safe - Frees a listint_t list safely (ie.
 *                     can free lists containing loops)
 * @h: A pointer to the address of
 *     the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 *
 * Description: The function sets the head to NULL.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp;
	size_t n_nodes, index;

	n_nodes = looped_listint_count(*h);

	if (n_nodes == 0)
	{
		for (; h != NULL && *h != NULL; n_nodes++)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
		}
	}

	else
	{
		for (index = 0; index < n_nodes; index++)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
		}

		*h = NULL;
	}

	h = NULL;

	return (n_nodes);
}
