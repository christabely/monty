#include "monty.h"
/**
 * printstack_top - function prints the head
 * @h: stack top
 * @counter: for line
 * Return: void
 */

void printstack_top(stack_t **h, unsigned int counter)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}
