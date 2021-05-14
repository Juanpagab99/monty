#include "monty.h"
/**
* main - monty bytecode interprenter
* @argc:Number of parameters
* @argv:pointer to all the parameters
* Return: EXIT_FAILURE or EXIT_SUCCESS
*/
int main(int argc, char **argv)
{
	stack_t *head;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	_open(argv[1], &head);
}
