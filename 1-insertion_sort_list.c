#include "sort.h"
/**
 * swap - sswap the nodes
 * @change: node to change
 * @list: head of list
 * Return: nothing
 */
void swap(listint_t *change, listint_t **list)
{
	while (change->prev && change->prev->n > change->n)
	{
		if (change->next)
			change->next->prev = change->prev;
		change->prev->next = change->next;
		change->next = change->prev;
		change->prev = change->prev->prev;
		change->next->prev = change;
		if (change->prev)
			change->prev->next = change;
		else
			*list = change;
		print_list(*list);
	}
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: head of list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *change = NULL, *current = NULL;

	if(!list || !*list)
		return;
	current = (*list)->next;
	while (current)
	{
		if (current->n < current->prev->n)
		{
			change = current;
			current = current->next;
			swap(change, list);
		}
		else
			current = current->next;
	}
}
