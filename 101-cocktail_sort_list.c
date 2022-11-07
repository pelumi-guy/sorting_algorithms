#include "sort.h"
#include <stdio.h>

listint_t *shift_backward(listint_t *node, listint_t **dl_list);
listint_t *shift_forward(listint_t *node);

/**
 * cocktail_sort_list - a function that sorts a doubly linked list
 * of integers in ascending order using
 * the Cocktail shaker sort algorithm
 * Description:
 * @list: head node of doubly linked list to sort
 * Return:
 **/

void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *head;
	int swapped;

	current = head = *list;

	if (list == NULL || head == NULL || head->next == NULL)
		return;

	while (1)
	{
		swapped = 0;
		/* printf("Beginning first pass forward wheee...\n"); */
		while (current->next)
		{
			if (current->next->n < current->n)
			{
				current = shift_forward(current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}

		/* printf("End of first pass\n"); */
		/* printf("Beginning second pass backwards wheee...\n"); */

		while (current->prev)
		{
			if (current->prev->n > current->n)
			{
				current = shift_backward(current, list);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
		/* printf("End of one trip round the loop\n"); */
		if (swapped == 0)
			break;
	}
}

/**
 * shift_backward - swap the node of a doubly-linked list
 * to the previous node
 * @node: the node of the list to swap
 * @dl_list: the whole doubly-linked list
 * Return: the list with the swapped nodes
 */
listint_t *shift_backward(listint_t *node, listint_t **dl_list)
{
	listint_t *previous_node = node->prev, *this_node = node;

	previous_node->next = this_node->next;
	if (this_node->next)
		this_node->next->prev = previous_node;

	this_node->prev = previous_node->prev;
	this_node->next = previous_node;
	previous_node->prev = this_node;

	if (this_node->prev)
		this_node->prev->next = this_node;
	else
		*dl_list = this_node;

	return (this_node);
}

/**
 * shift_forward - swap the node of a doubly-linked list
 * to the next node
 * @node: the node of the list to swap
 * Return: the list with the swapped nodes
 */
listint_t *shift_forward(listint_t *node)
{
	listint_t *next_node = node->next, *this_node = node;

	next_node->prev = this_node->prev;
	if (this_node->prev)
		this_node->prev->next = next_node;

	this_node->next = next_node->next;
	this_node->prev = next_node;
	next_node->next = this_node;

	if (this_node->next)
		this_node->next->prev = this_node;

	return (this_node);
}
