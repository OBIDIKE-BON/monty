#include "monty.h"

/**
 * safeStrToInt - convert string to int.
 * @str: error message
 * @line: line number
 * @tok: opcode
 * @stack: stack of ints
 * Return: int
 */
int safeStrToInt(char *str, int line, char *tok, stack_t *stack)
{
	char *endptr;
	long num;

	errno = 0; /* Reset errno before the call */
	num = strtol(str, &endptr, 10);

	if (errno == ERANGE || num > INT_MAX || num < INT_MIN)
	{
		val.err_code = -1;
		print_err("", "unknown instruction ", stack, line, tok);
	}

	if (endptr == str)
	{
		val.err_code = -1;
		print_err("", "unknown instruction ", stack, line, tok);
	}
	/* Check for trailing characters */
	while (*endptr != '\0')
	{
		if (!isspace(*endptr))
		{
		val.err_code = -1;
		print_err("", "unknown instruction ", stack, line, tok);
		}
		endptr++;
	}

	val.data = (int)num;
	return (0);
}

/**
 * print_err - Print a string to the standard output stream.
 * @str: error header
 * @err: error message
 * @stack: stack to be freed before exiting
 * @ln: line number
 * @tok: token
 */
void print_err(char *str, char *err, stack_t *stack, int ln, char *tok)
{
	free_stack(stack);
	if (val.err_code == -1)
		fclose(val.fstream);
	if (val.buf)
		free(val.buf);
	if (ln > 0)
		fprintf(stderr, "L%d: %s %s\n", ln, err, tok); /* Write the string to the standard error*/
	else
		fprintf(stderr, "%s: %s %s\n", str, err, tok); /* Write the string to the standard error*/
	exit(EXIT_FAILURE);
}

/**
 * pall - prints all data in the stack
 * @line_num: line number
 * @stack: stack of ints
 */
void pall(stack_t **stack, unsigned int line_num)
{
	int i = 0;
	stack_t *tmp = *stack;
	(void)line_num;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		i++;
	}
}
