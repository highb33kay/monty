#include "monty.h"

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	FILE *monty_file;
	char *filename;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	filename = argv[1];
	monty_file = fopen(filename, "r");

	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}

	while (getline(&line, &len, monty_file) != -1)
	{
		line_number++;
		_execute(&stack, line_number, line);
	}

	free(line);
	fclose(monty_file);
	free_stack(&stack);

	return (EXIT_SUCCESS);
}
