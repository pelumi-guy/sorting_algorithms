#include "sort.h"

/**
 * shift_list_node - swap the node of a doubly-linked list
 * to the next node
 * @node: the node of the list to swap
 * @dl_list: the whole doubly-linked list
 * Return: the list with the swapped nodes
 */
listint_t *shift_list_node(listint_t *node, listint_t **dl_list)
{
	listint_t *previous_node = node->prev, *this_node = node;

	previous_node->next = this_node->next;
	if (this_node->next)
	{
		this_node->next->prev = previous_node;
	}
	this_node->prev = previous_node->prev;
	this_node->next = previous_node;
	previous_node->prev = this_node;

	if (this_node->prev)
	{
		this_node->prev->next = this_node;
	}
	else
	{
		*dl_list = this_node;
	}
	return (this_node);
}

/**
 * insertion_sort_list - sort the list using the insertion sort method
 * @list: the doubly-linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL)
		return;

	if ((*list)->next == NULL)
		return;

	node = (*list)->next;
	while (node)
	{
		while (node->prev && node->prev->n > node->n)
		{
			node = shift_list_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
