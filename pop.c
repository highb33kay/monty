#include "monty.h"
/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;

	printf("%d\n", temp->n);
	free(temp);
}
