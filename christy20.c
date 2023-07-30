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
				{"push", _fpush}, {"pall", _fpall}, {"pint", printstack_top},
				{"pop", pop_element},
				{"swap", _fswap},
				{"add", _fadd},
				{"nop", _fnop},
				{"sub", _fsub},
				{"div", _fdiv},
				{"mul", _fmul},
				{"mod", _fmod},
				{"pchar", _fpchar},
				{"pstr", _fpstr},
				{"rotl", _frotl},
				{"rotr", _frotr},
				{"queue", _fqueue},
				{"stack", _fstack},
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
