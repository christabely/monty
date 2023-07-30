#include "monty.h"

/**
 * execute - function that interprets instruction by opcode
 * @stack: top linked list
 * @counter: line_tracker
 * @file: monty file
 * @content: line content
 * Return: void
 */

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", _fpush}, {"pall", display_stack}, {"pint", printstack_top},
				{"pop", pop_element},
				{"swap", _fswap},
				{"add", add_stack},
				{"nop", _fnop},
				{"sub", _fsub},
				{"div", _fdiv},
				{"mul", smul},
				{"mod", _modulo},
				{"pchar", pchar},
				{"pstr", _fpstr},
				{"rotl", move_top},
				{"rotr", _frotr},
				{"queue", _fqueue},
				{"stack", out_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *mp;

	mp = strtok(content, " \n\t");
	if (mp && mp[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && mp)
	{
		if (strcmp(mp, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (mp && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, mp);
		fclose(file);
		free(content);
		freestack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
