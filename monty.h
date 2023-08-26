#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct mData - for err handling and data
 * @fstream: file stream
 * @data: function to handle the opcode
 * @err_code: function to handle the opcode
 * @buf: function to handle the opcode
 * @chk: checker
 */
typedef struct mData
{
	FILE *fstream;
	int data;
	int err_code;
	char *buf;
	int chk;
} val_t;
extern val_t val;

int safeStrToInt(char *str, int line, char *tok, stack_t *stack);
void exec_ops(char *buf, instruction_t ops[], int line_num, stack_t **stack);
void print_err(char *str, char *err, stack_t *stk, int ln, char *tok, char *t);
void free_stack(stack_t *stack);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);

#endif /* MONTY_H */
