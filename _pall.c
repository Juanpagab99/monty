#include "monty.h"
/**
* _pall - stack values
* @stack: head
* @i: line numbers
*
*/
void _pall(stack_t **stack, unsigned int i __attribute_((unused)))
{
	stack_t *auxiliar = *stack;

	if (*stack == NULL)
	{
		return;
	}
	aux = *stack;
	while (aux != NULL)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
