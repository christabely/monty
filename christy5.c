#include "monty.h"
/**
 * smul - function that computes two elements of the stack.
 * @h: the stack head
 * @counter: line_index
 * Return: void
 */

void smul(stack_t **h, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*h);
		exit(EXIT_FAILURE);
	}
	m = *h;
	aux = m->next->n * m->n;
	m->next->n = aux;
	*h = m->next;
	free(m);
}
