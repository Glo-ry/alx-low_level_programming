#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the beginning of the linked list
 * @idx: index at which to insert the new node
 * @n: data to enter into new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp, *current = *h;
	unsigned int i;

	if (h == NULL)
		return NULL;

	/* Special case: Insert at the beginning */
	if (idx == 0)
		return add_dnodeint(h, n);

	/* Traverse to the desired index or the end of the list */
	for (i = 0; i < idx - 1 && current != NULL; i++)
		current = current->next;

	/* If the index is out of range, return NULL */
	if (current == NULL)
		return NULL;

	/* Create a new node and assign the data */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return NULL;
	new_node->n = n;

	/* Adjust the pointers to insert the new node */
	temp = current->next;
	current->next = new_node;
	new_node->prev = current;
	new_node->next = temp;

	if (temp != NULL)
		temp->prev = new_node;

	return new_node;
}
