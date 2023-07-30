#include "monty.h"
/**
 * display_stack - function outputs the stack
 * @h: stack top point
 * @counter: not utilized
 * Return: void
*/

void display_stack(stack_t **h, unsigned int counter)
{
	stack_t *m;
	(void)counter;

	m = *h;
	if (m == NULL)
		return;
	while (m)
	{
		printf("%d\n", m->n);
		m = m->next;
	}
}
