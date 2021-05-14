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
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL ; i++)
	{
		if (strcmp(ops[i].opcode, option) == 0)
		{
			ops[i].f(stack, i);
			return;
		}
		printf("L%u: unknown instruction %s\n", i, option);
		exit(EXIT_FAILURE);
	}
}
#include "monty.h"
/**
* _open - open file if file exist
* @file: file
* @stack: pointer to list
*/
void _open(char *file, stack_t **stack)
{
	ssize_t line;
	size_t buffsize;
	unsigned int j = 0;
	char *linea = NULL;
	FILE *opn;
	char *option;

	opn = fopen(file, "r");
	if (!opn)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while (line = getline(&linea, &buffsize, opn) != -1)
	{
		option = strtok(linea, " /t/n/r");
		j++;
	}
	free(linea);
	free(opn);
}
