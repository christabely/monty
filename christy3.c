#include "monty.h"

/**
 * freestack - function that releases a doubly linked list
 * @h: stack top
 */

void freestack(stack_t *h)
{
	stack_t *aux;

	aux = h;
	while (h)
	{
		aux = h->next;
		free(h);
		h = aux;
	}
}
