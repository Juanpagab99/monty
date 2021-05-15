#include "monty.h"
/**
* get_function - get a function
* @option:operator
* @stack: pointer to linked list
* @line_number: line number
*/
void get_function(char *option, stack_t **stack, unsigned int line_number)
{
	size_t i = 0;

	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{NULL, NULL}};

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, option) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, option);
	exit(EXIT_FAILURE);
}
