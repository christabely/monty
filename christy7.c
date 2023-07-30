#include "monty.h"
/**
 * pchar - function that outputs character at the top of the stack
 * @h: stack top
 * @counter: line_index
 * Return: void
*/

void pchar(stack_t **h, unsigned int counter)
{
	stack_t *m;

	m = *h;
	if (!m)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*h);
		exit(EXIT_FAILURE);
	}
	if (m->n > 127 || m->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", m->n);
}
