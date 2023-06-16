#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - This adds a node to the end of a linked list
 * @head: double pointer to the beginning of the linked list
 * @n: value to add to new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	if (head == NULL)
		return NULL;

	dlistint_t *new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return NULL;

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return new;
	}

	dlistint_t *current = *head;
	while (current->next != NULL)
		current = current->next;

	current->next = new;
	new->prev = current;
	return new;
}
