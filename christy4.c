#include "monty.h"
/**
 * _modulo - function evaluates element of the stack
 * @h: stack head
 * @counter: line_index
 * Return: void
 */

void _modulo(stack_t **h, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*h);
		exit(EXIT_FAILURE);
	}
	m = *h;
	if (m->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*h);
		exit(EXIT_FAILURE);
	}
	aux = m->next->n % m->n;
	m->next->n = aux;
	*h = m->next;
	free(m);
}
