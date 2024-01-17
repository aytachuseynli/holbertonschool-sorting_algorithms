#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the Insertion sort algorithm.
 * @list: Double pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->prev->next = current->next;

			current->next = current->prev;
			current->prev = current->prev->prev;

			if (current->prev != NULL)
				current->prev->next = current;

			if (current->next == NULL)
				*list = current;

			print_list(*list);
		}

		current = temp;
	}
}
