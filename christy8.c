#include "monty.h"
/**
 * _fpint - function prints the head
 * @h: stack top
 * @counter: line_index
 * Return: void
*/
void _fpint(stack_t **h, unsigned int counter)
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
