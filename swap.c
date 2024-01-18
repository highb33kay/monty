#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next)
		temp->next->prev = *stack;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
