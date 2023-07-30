#include "monty.h"

/**
 * add_stack - sums the top two elements of the stack.
 * @h: stack head
 * @counter: for line
 * Return: void
*/

void add_stack(stack_t **h, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*h);
		exit(EXIT_FAILURE);
	}
	m = *h;
	aux = m->n + m->next->n;
	m->next->n = aux;
	*h = m->next;
	free(m);
}
