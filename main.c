#include "monty.h"
/**
* main - main function
* @argc: number of arguments
* @argv: arguments
* Return: EXIT_FAILURE or EXIT_SUCCESS
*/
int main(int argc, char *argv[])
{
	FILE *stream = NULL;
	char *line = NULL, *delim = NULL;
	size_t line_number = 0, len = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, stream) != EOF)
	{
		line_number++;
		delim = strtok(line, " \t\n\r\a");
		if (delim != NULL && delim[0] != '#')
		{
			get_function(delim, &stack, line_number);
		}
	}
	free(line);
	free_s(stack);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
