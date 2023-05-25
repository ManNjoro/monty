#include "monty.h"

/**
 * nop - does nothing
 * @n: pointer
 * @line_n: line number
 * Return: void
 */
void nop(stack_t **n, unsigned int line_n)
{
	(void) n;
	(void) line_n;
}

/**
 * swap - swaps the top two elements of the stack.
 * @n: pointer
 * @line_n: line number
 * Return: void
 */

void swap(stack_t **n, unsigned int line_n)
{
	int temp;

	if (*n == NULL || (*n)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	temp = (*n)->n;
	(*n)->n = (*n)->next->n;
	(*n)->next->n = temp;
}

/**
 * add - adds the top two elements of the stack
 * @n: ...
 * @line_n: ...
 * Return: void
 */
void add(stack_t **n, unsigned int line_n)
{
	int result;

	if (*n == NULL || (*n)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	result = (*n)->n + (*n)->next->n;
	pop(n, line_n);
	(*n)->n = result;
}

