/*
 * File: 7-get_nodeint.c
 * Auth: Victoria E Iria
 * A function that returns the nth node of a listint_t linked list.
 */

#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a linked list
 * @head: A pointer to the head of the listint_t list.
 * @index: which node to fetch from a list starting at 0.
 *
 * Return: If the node does not exist - NULL.
 *         Otherwise - the located node.
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *caret = NULL;

	if (!head)
		return (NULL);

	caret = head;
	while (i < index)
	{
		if (!caret)
			return (NULL);
		caret = caret->next;
		i++;
	}
	return (caret);
}

