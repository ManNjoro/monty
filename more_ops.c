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

