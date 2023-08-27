#include "monty.h"

/**
 * pstr - prints ascii value of the n member of the stack list
 * @stack: pointer to the topmost element of the stack
 * @line_number: line containing "pstr" opcode
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	while (tmp && (tmp->n > 0 && tmp->n < 128))
	{
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * pchar - prints ascii value at top of the stack
 * @stack: pointer to the topmost element of the stack
 * @line_num: line containing "pchar" opcode
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_num)
{
	char *msg = "can't pchar, value out of range";

	if (*stack)
	{
		if ((*stack)->n > 0 && (*stack)->n < 128)
		{
			printf("%c\n", (*stack)->n);
		}
		else
		{
			val.err_code = -1;
			print_err("", msg, *stack, line_num, "", "");
		}
	}
	else
	{
		val.err_code = -1;
		print_err("", "can't pchar, stack empty", *stack, line_num, "", "");
	}
}
