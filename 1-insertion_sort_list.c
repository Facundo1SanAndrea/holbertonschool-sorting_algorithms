#include "sort.h"

/**
 * insertion_sort_list - sorts a list of ints order asc(Insertion algorithm)
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *n1 = NULL;
	listint_t *n2 = NULL;
	listint_t *more_advanced_node = NULL;

	if (!list)
	return;

	n1 = *list;
	if (!n1)
		return;

	n2 = n1->next;
	if (!n2)
		return;


	while (n2)
	{
		if (n1->n > n2->n)
		{
			more_advanced_node = n2;
			swap_nodes(list, n1, n2);
			print_list(*list);
			n1 = n2->prev;
			while (n1 && n1->n > n2->n)
			{
				swap_nodes(list, n1, n2);
				print_list(*list);
				n1 = n2->prev;
			}
			n1 = more_advanced_node;
			n2 = more_advanced_node->next;
		}
		n1 = n2;
		n2 = n2->next;
	}
}

/**
 * swap_nodes - swap node from dobly linked list
 * @list: doubly linked list
 * @n1: first node
 * @n2: second node
 */
void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	listint_t *n1prev = NULL;
	listint_t *n1next = NULL;
	listint_t *n2prev = NULL;
	listint_t *n2next = NULL;

	if (!n1 || !n2)
		return;

	n1prev = n1->prev;
	n1next = n1->next;
	n2prev = n2->prev;
	n2next = n2->next;

	n1->prev = n2prev == n1 ? n2 : n2prev;
	n1->next = n2next;
	n2->prev = n1prev;
	n2->next = n1next == n2 ? n1 : n1next;

	if (n1prev)
		n1prev->next = n2;

	if (n1next && n1next != n2)
		n1next->prev = n2;

	if (n2next)
		n2next->prev = n1;

	if (n2prev && n2prev != n1)
		n2prev->next = n1;

	if (*list == n1)
		*list = n2;
}
