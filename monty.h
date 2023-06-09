#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
extern int global_var;
int global_var;
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
 * struct instruction_s - opcoode and its function
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

char *get_tokens(char *line, unsigned int line_number);
void push(stack_t **n, unsigned int line_n);
void push_func(stack_t **stack, unsigned int line_number);
void pall(stack_t **n, unsigned int line_n);
void pint(stack_t **n, unsigned int line_n);
void pop(stack_t **n, unsigned int line_n);
void nop(stack_t **n, unsigned int line_n);
void swap(stack_t **n, unsigned int line_n);
void add(stack_t **n, unsigned int line_n);
void sub(stack_t **n, unsigned int line_n);
void div_func(stack_t **stack, unsigned int line_number);
void mul_func(stack_t **stack, unsigned int line_number);
void get_func(char *op, stack_t **stack, unsigned int line_number);
int is_number(char *s);
void free_stack(stack_t *head);

#endif
