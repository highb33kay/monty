#include "monty.h"

/**
 * push_to_stack - Pushes a new node with the given value to the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @value: Value to be pushed onto the stack.
 */
void push_to_stack(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;

	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}

	*stack = new_node;
}
