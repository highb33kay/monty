#include "monty.h"
#include <stddef.h>

/**
 * free_stack - Frees a stack_t stack.
 * @stack: Pointer to the top of the stack.
 */
void free_stack(stack_t **stack)
{
	stack_t *current, *temp;

	current = *stack;

	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}

	*stack = NULL;
}
