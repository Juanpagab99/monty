#include "monty.h"
/**
* _pall - stack values
* @stack: head
* @i: line numbers
*/
void _pall(stack_t **stack, unsigned int i __attribute__((unused)))
{
	stack_t *auxiliar = *stack;

	if (*stack == NULL)
	{
		return;
	}
	auxiliar = *stack;
	while (auxiliar != NULL)
	{
		printf("%d\n", auxiliar->n);
		auxiliar = auxiliar->next;
	}
}
