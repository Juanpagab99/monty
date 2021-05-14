#include "monty.h"

void _push(stack_t **stack, unsigned int line_number)
{
	char *n;
	stack_t *new;

	n = strtok(NULL, " \n\r\t");
	if (n == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(n);
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}

	*stack = new;
}

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		if (tmp == *stack)
		{
			return;
		}
	}
}

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (*stack != NULL)
	{
		printf("%d\n", head->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}