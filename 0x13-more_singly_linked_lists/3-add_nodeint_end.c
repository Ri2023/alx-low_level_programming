/*
 * File: 3-add_nodeint_end.c
 * Auth: Iria E Victoria
 * A programme that adds a new node at the end of a listint_t list.
 */

#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the
 *                   end of a listint_t list.
 * @head: A pointer to the address of the
 *        head of the listint_t list.
 * @n: The integer for the new node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new element.
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *caret = *head;

	new_node = malloc(sizeof(listint_t));
	if (new_node != NULL)
	{
		new_node->n = n;
		new_node->next = NULL;
	}
	else
		return (NULL);
	if (caret != NULL)
	{
		while (caret->next != NULL)
			caret = caret->next;
		caret->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}
