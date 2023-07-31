#include "monty.h"

/**
 * _crotr- repositions the stack to the bottom
 * @h: stack top
 * @counter: line_index
 * *Return: void
 */

void _crotr(stack_t **h, __attribute__((unused)) unsigned int counter)
{
	stack_t *cpy;

	cpy = *h;
	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	while (cpy->next)
	{
		cpy = cpy->next;
	}
	cpy->next = *h;
	cpy->prev->next = NULL;
	cpy->prev = NULL;
	(*h)->prev = cpy;
	(*h) = cpy;
}
