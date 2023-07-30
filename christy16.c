#include "monty.h"

/**
 * _fpstr - function that outputs string from top of stack
 * @h: head of stack
 * @counter: line
 * Return: void
 */

void _fpstr(stack_t **h, unsigned int counter)
{
	stack_t *m;
	(void)counter;

	m = *h;
	while (m)
	{
		if (m->n > 127 || m->n <= 0)
		{
			break;
		}
		printf("%c", m->n);
		m = m->next;
	}
	printf("\n");
}
