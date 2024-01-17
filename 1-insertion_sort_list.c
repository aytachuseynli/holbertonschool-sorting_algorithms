#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *insert;

	current = (*list)->next;

	while (current != NULL)
	{
		insert = current;

		while (insert->prev != NULL && insert->n < insert->prev->n)
		{
			if (insert->next != NULL)
				insert->next->prev = insert->prev;

			insert->prev->next = insert->next;
			insert->next = insert->prev;
			insert->prev = insert->next->prev;
			insert->next->prev = insert;

			if (insert->prev == NULL)
				*list = insert;
		}

		current = current->next;
	}

	print_list(*list);
}
