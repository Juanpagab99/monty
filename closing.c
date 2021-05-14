#include "monty.h"

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