#include "monty.h"

/**
 * _cqueue - function prints the head
 * @h: stack head
 * @counter: line
 * Return: void
 */

void _cqueue(stack_t **h, unsigned int counter)
{
	(void)h;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - function add node to tail stack
 * @n: new_value
 * @h: head of the stack
 * Return: no return
 */

void addqueue(stack_t **h, int n)
{
	stack_t *new_node, *aux;

	aux = *h;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*h = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
