#include "monty.h"

/**
 * swap_stack - function that combines elements of stack
 * @h: head of stack
 * @counter: line index
 * Return: void
 */

void swap_stack(stack_t **h, unsigned int counter)
{
	stack_t *m;
	int len = 0, aux;

	m = *h;
	while (m)
	{
		m = m->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*h);
		exit(EXIT_FAILURE);
	}
	m = *h;
	aux = m->n;
	m->n = m->next->n;
	m->next->n = aux;
}
