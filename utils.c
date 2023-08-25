#include "monty.h"

/**
 * free_stack - frees a doubly liked list.
 * @stack: poiter to the list head.
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	if (stack == NULL)
		return;
	while (stack->next)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	free(stack);
}
