#include "lists.h"

/**
 * dlistint_len - a function that returns the number of
 * elements in a linked dlistint_t list
 * @h: pointer to the beginning of a linked list
 *
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t g;

	for (g = 0; h != NULL; g++)
		h = h->next;
	return (g);
}
