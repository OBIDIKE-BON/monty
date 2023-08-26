#include "monty.h"

void t(void);
val_t val;

/**
 * pint - prints the last element of a list
 * @line_num: line number
 * @stack: stack of ints
 */
void pint(stack_t **stack, unsigned int line_num)
{
	stack_t *new;
	if (val.chk != 0)
	{
		val.err_code = -1;
		print_err("", "unknown instruction ", *stack, line_num, "push");
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		val.err_code = -1;
		print_err("Error", "malloc failed", *stack, line_num, "");
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
		print_err("", "usage:", *stack, line_num, "push integer");
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		val.err_code = -1;
		print_err("Error", "malloc failed", *stack, line_num, "");
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
 * exec_ops - find appriopriate funcs
 * @buf: line buffer
 * @ops: Array containing funcs
 * @line_num: line number
 * @stack: stack of ints
 */
void exec_ops(char *buf, instruction_t ops[], int line_num, stack_t **stack)
{
	char *tok1, *tok2 = NULL, *delim = " \n\t\r";
	int i;

	val.chk = -1;
	tok1 = strtok(buf, delim);
	if (tok1)
	{
		tok2 = strtok(NULL, delim);
		if (tok2 != NULL)
		{
			val.chk = safeStrToInt(tok2, line_num, tok1, *stack); /** edge case for 0 **/
		}
		/* looping through array of funcs */
		i = 0;
		while (ops[i].opcode)
		{
			if (strcmp(ops[i].opcode, tok1) == 0)
			{
				ops[i].f(stack, line_num);
				break;
			}
			i++;
		}
		if (ops[i].opcode == NULL)
		{
			val.err_code = -1;
			print_err("", "unknown instruction ", *stack, line_num, tok1);
		}
	}
}

/**
 * main - Entry point of the program
 * @ac: The number of command-line arguments
 * @av: Array containing the command-line arguments
 *
 * Return: Exit status of the program
 */

int main(int ac, char **av)
{
	char *buf = NULL;
	size_t n = 0;
	FILE *fstream;
	int line_num = 0;
	stack_t *stack = NULL;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pint},
		{"pint", pall},
		{"pop", pall},
		{"swap", pall},
		{NULL, NULL}};

	val.err_code = 0;
	val.buf = NULL;
	val.fstream = NULL;
	av[1] = "000.m";
	ac = 2;
	if (ac != 2)
		print_err("USAGE", "monty file", stack, -1, "");
	fstream = fopen(av[1], "r");
	if (!fstream)
	{
		print_err("Error", "Can't open file ", stack, -1, av[1]);
	}
	val.fstream = fstream;
	while (getline(&buf, &n, fstream) != -1)
	{
		val.buf = buf;
		line_num++;
		exec_ops(buf, ops, line_num, &stack);
	}
	fclose(fstream);
	free_stack(stack);
	free(buf);
	exit(EXIT_SUCCESS);
}
