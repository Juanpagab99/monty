#include "monty.h"

/**
* _pop - function that removes the top element of the stack
* @stack: pointer to linked list
* @line_number: line number
*
* Return: Nothing.
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	if (tmp->next)
        tmp->next->prev = NULL;
    *stack = tmp->next;
    tmp->next = NULL;
	*stack = (*stack)->next;
	free(tmp);
}

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
