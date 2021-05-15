#include "monty.h"
/**
* free_s - free all
* @stack: important pointer
*/
void free_s(stack_t *stack)
{
	stack_t *tmp = NULL;

	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
