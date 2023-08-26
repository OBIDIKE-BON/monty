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

/**
 * push - adds data to stack
 * @line_num: line number
 * @stack: stack of ints
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new;

	if (val.chk != 0)
	{
		val.err_code = -1;
		print_err("", "usage: ", *stack, line_num, "push ", "integer");
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		val.err_code = -1;
		print_err("Error", "malloc", *stack, -1, " ", "failed");
	}
	new->n = val.data;

	if (*stack == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return;
	}

	new->next = *stack;
	(*stack)->prev = new;
	(*stack)->prev = NULL;
	*stack = new;
}

/**
 * swap - swaps top two on the stack
 * @line_num: line number
 * @stack: stack of ints
 */
void swap(stack_t **stack, unsigned int line_num)
{
	int n;
	if (*stack && (*stack)->next)
	{
		n = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = n;
	}	
	else
	{
		val.err_code = -1;
		print_err("", "can't swap, stack too short", *stack, line_num, "", "");
	}
}