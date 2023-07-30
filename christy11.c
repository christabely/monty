#include "monty.h"

/**
 * move_top - function that repositions stack to the top
 * @h: stack top
 * @counter: line_imndex
 * Return: void
 */

void move_top(stack_t **h,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *h, *aux;

	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	aux = (*h)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *h;
	(*h)->next = NULL;
	(*h)->prev = tmp;
	(*h) = aux;
}
