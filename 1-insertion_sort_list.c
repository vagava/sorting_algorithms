#include "sort.h"
/**
 * SearchPlace - search the place to insert the node
 * @place: place to insert the node
 * @change: value to compare the value of place
 * Return: pointer to place to insert the node
 */
listint_t *search_place(listint_t *place, listint_t *change)
{
	while (place->prev && place->prev->n > change->n)
		place = place->prev;
	return (place);
}
/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: head of list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *place = NULL, *change = NULL, *current = NULL;

	current = (*list)->next;

	while (current)
	{
		if (current->n < current->prev->n)
		{
			change = current;
			if (current->next)
			{
				current = current->next;
				current->prev = change->prev;
				change->prev->next = current;
			}
			else
			{
				change->prev->next = change->next;
				current = current->next;
			}
			place = SearchPlace(change->prev, change);
			change->prev = place->prev;
			change->next = place;
			if (place->prev)
				place->prev->next = change;
			else
				*list = change;
			place->prev = change;
			print_list(*list);
		}
		else
			current = current->next;
	}
}
