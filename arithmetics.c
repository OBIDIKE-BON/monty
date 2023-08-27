#include "monty.h"

/**
 * sub - sbtracts top element from second top element of the stack
 * @line_num: line number
 * @stack: stack of ints
 */
void sub(stack_t **stack, unsigned int line_num)
{
	int n;

	if (*stack && (*stack)->next)
	{
		n = (*stack)->next->n - (*stack)->n;
		(*stack)->next->n = n;
		pop(stack, line_num);
	}
	else
	{
		val.err_code = -1;
		print_err("", "can't sub, stack too short", *stack, line_num, "", "");
	}
}

/**
 * div - divides second top element by top element of the stack
 * @line_num: line number
 * @stack: stack of ints
 */
void div(stack_t **stack, unsigned int line_num)
{
	int n;

	if ((*stack)->n == 0)
		print_err("", "division by zero", *stack, line_num, "", "");

	if (*stack && (*stack)->next)
	{
		n = (*stack)->next->n / (*stack)->n;
		(*stack)->next->n = n;
		pop(stack, line_num);
	}
	else
	{
		val.err_code = -1;
		print_err("", "can't div, stack too short", *stack, line_num, "", "");
	}
}
