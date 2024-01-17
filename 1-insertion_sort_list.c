#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Insertion sort.
 * @list: Pointer to the list to sort.
 */
void insertion_sort_list(listint_t **list)
{
    if (!list || !*list || !(*list)->next)
        return;

    listint_t *temp, *current = (*list)->next;

    while (current)
    {
        temp = current->next;

        while (current->prev && current->n < current->prev->n)
        {
            current->prev->next = current->next;
            if (current->next)
                current->next->prev = current->prev;
            current->next = current->prev;
            current->prev = current->prev->prev;
            current->next->prev = current;
            *list = current->prev ? *list : current;
            print_list(*list);
        }

        current = temp;
    }
}
