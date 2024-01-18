#include "monty.h"

/**
 * get_op_function - Retrieves the function pointer associated with an opcode.
 * @opcode: The opcode.
 * Return: Function pointer or NULL if not found.
 */
instruction_t *get_op_function(const char *opcode)
{
	int i;

	static instruction_t op_functions[] = {
		{"push", push},
		{"pall", pall},

		{NULL, NULL}};

	for (i = 0; op_functions[i].opcode; i++)
	{
		if (strcmp(op_functions[i].opcode, opcode) == 0)
		{
			instruction_t *result = malloc(sizeof(instruction_t));

			if (!result)
			{
				fprintf(stderr, "Error: malloc failed in get_op_function\n");
				exit(EXIT_FAILURE);
			}

			memcpy(result, &op_functions[i], sizeof(instruction_t));
			return (result);
		}
	}

	return (NULL);
}
