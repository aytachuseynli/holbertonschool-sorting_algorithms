#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm.
 * @list: Double pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	if (!list || !(*list) || !(*list)->next)
		return;

	listint_t *curr = (*list)->next;
	listint_t *next, *prev;

	while (curr)
	{
		next = curr->next;

		while (curr->prev != NULL && curr->prev->n > curr->n)
		{
			prev = curr->prev;

			if (curr->next)
				curr->next->prev = prev;

			prev->next = curr->next;
			curr->next = prev;
			curr->prev = prev->prev;

			if (prev->prev)
				prev->prev->next = curr;
			else
				*list = curr;

			prev->prev = curr;

			print_list(*list);
		}

		curr = next;
	}
}
