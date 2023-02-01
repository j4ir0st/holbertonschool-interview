#include "lists.h"
/**
 * check_cycle - Check if a singly linked list has a cycle in it
 * @list: pointer to linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *turtle = list, *rabbit = list;

	if (list == NULL)
		return (0);
	while (rabbit != NULL && rabbit->next != NULL && rabbit->next->next != NULL)
	{
		turtle = turtle->next;
		rabbit = rabbit->next->next;
		if (turtle == rabbit)
			return (1);
	}
	return (0);
}
