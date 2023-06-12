/*
 * File: 100-reverse_listint.c
 * Auth: Victoria E Iria
 * A function that reverses a listint_t linked list.
 */

#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t list.
 * @head: A pointer of a pointer to a list.
 *
 * Return: A pointer to the first node of the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *new_node = NULL;
	listint_t *old_node = NULL;

	if (head == NULL)
		return (NULL);
	while (*head != NULL)
	{
		new_node = (*head)->next;
		(*head)->next = old_node;
		old_node = *head;
		*head = new_node;
	}
	*head = old_node;
	return (*head);
}
