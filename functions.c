#include "monty.h"

/**
 * _isdigit - is digit or not
 * @c: number or letter
 * Return: 1 or 0
*/
int _isdigit(char *c)
{
	if (!c || *c == '\0')
		return (0);

	if (*c == '-')
		c++;

	while (*c)
	{
		if (isdigit(*c) == 0)
			return (0);
		c++;
	}

	return (1);
}

/**
* _push - add node
* @stack: pointer to linked list
* @line_number: line number
*
*/
void _push(stack_t **stack, unsigned int line_number)
{
	char *n;
	stack_t *node;

	n = strtok(NULL, " \n\r\t\a");
	if ((_isdigit(n)) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
		free(node);
	}

	node->n = atoi(n);
	node->prev = NULL;
	node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = node;
	}

	*stack = node;
}
/**
* _pall - all values on the stack
* @stack: pointer to linked list
* @line_number: line number
*/
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
/**
* _pint - show first variable
* @stack: pointer to linked list
* @line_number: line number
*/
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
