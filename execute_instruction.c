#include "monty.h"

/**
 * _execute - Executes the Monty bytecode instruction.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 * @instruction: Monty instruction to be executed.
 */
void _execute(stack_t **stack, unsigned int line_number, char *instruction)
{
	char *opcode;
	instruction_t *op_function;

	opcode = strtok(instruction, " \t\n");

	if (!opcode || opcode[0] == '#')
		return;

	op_function = get_op_function(opcode);

	if (!op_function)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}

	op_function->f(stack, line_number);
}
