/*
 * File: 10-delete_nodeint.c
 * Auth: Victoria E Victoria
 * a function that deletes the node at index index of a listint_t linked list.
 */

#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the node at index index of a
 * listint_t linked list.
 * @head: A pointer to the address of the
 *        head of the listint_t list.
 * @index: The index of the node to be deleted - indices start at 0.
 *
 * Return: On success 1.
 *         On failure -1.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *node, *pre;

	if (!(*head))
		return (-1);
	i = 0;
	pre = NULL;
	node = *head;

	if (!index)
	{
		(*head) = (*head)->next;
		free(node);
		return (1);
	}
	while (node)
	{
		if (i == index)
		{
			pre->next = node->next;
			free(node);
			return (1);
		}
		pre = node;
		node = node->next;
		i++;
	}

	return (-1);
}

