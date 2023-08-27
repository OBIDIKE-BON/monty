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
