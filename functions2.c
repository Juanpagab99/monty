#include "monty.h"
/**
* _swap - add new node
* @stack: important pointer
* @line_number: line number
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *auxiliar;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	auxiliar = (*stack)->next;
	(*stack)->prev = auxiliar;
	(*stack)->next = auxiliar->next;
	auxiliar->prev = NULL;
	if (auxiliar->next)
	{
		auxiliar->next->prev = *stack;
	}
	auxiliar->next = *stack;
	*stack = auxiliar;
}
