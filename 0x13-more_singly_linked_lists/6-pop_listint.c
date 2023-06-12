/*
 * File: 6-pop_listint.c
 * Auth: Victoria E Iria
 * A function that deletes the head node of a listint_t linked list,
 * and returns the head node’s data (n).
 */

#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t list.
 * @head: A pointer to the address of the
 *        head of the listint_t list.
 *
 * Return: If the linked list is empty - 0.
 *         Otherwise - The head node's data (n).
 */
int pop_listint(listint_t **head)
{
	listint_t *foo;
	int mash;

	if (*head == NULL)
		return (0);

	foo = *head;
	mash = (*head)->n;
	*head = (*head)->next;

	free(foo);

	return (mash);
}
