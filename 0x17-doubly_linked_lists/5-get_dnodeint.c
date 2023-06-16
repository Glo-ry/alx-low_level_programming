#include "lists.h"

/**
 * get_dnodeint_at_index - a function that returns the nth node
 * of a dlistint_t linked list
 * @head: pointer to the beginning of the list
 * @index: index of the node to retrieve
 *
 * Return: NULL if the node does not exist, return
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int g;

	if (head == NULL)
		return (NULL);
	if (index == 0)
		return (head);
	for (g = 0; g < index; g++)
	{
		if (head->next == NULL)
			return (NULL);
		head = head->next;
	}
	return (head);
}
