#include "monty.h"
/**
* main - monty bytecode interprenter
* @argc:Number of parameters
* @argv:pointer to all the parameters
* Return: EXIT_FAILURE or EXIT_SUCCESS
*/
int main(int argc, char **argv)
{
	FILE *file = NULL;
	stack_t *stack = NULL;
	size_t buff_size;
	ssize_t linea;
	char *buffer = NULL;
	char *option = NULL;
	unsigned int i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (linea = getline(&buffer, &buff_size, file) != -1)
	{
		i++;
		option = strtok(buffer, "\n\t\r ");
		if (option != NULL && option[0] != "#")
		{
			comp(option, &stack, i);
		}
	}
	exit(EXIT_SUCCESS);
}
