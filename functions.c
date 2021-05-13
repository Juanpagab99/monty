#include "monty.h"
/**
* comp - compare functions
* @option: command options
* @stack: double pointer to linked list
* @i: number line
*/
void comp(char *option, stack_t **stack, unsigned int i)
{
	size_t j;
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL ; i++)
	{
		if (strcmp(ops[i].opcode, op) == 0)
		{
			ops[i].f(stack, i);
			return;
		}
		printf("L%u: unknown instruction %s\n", i, option);
		exit(EXIT_FAILURE);
	}
}
