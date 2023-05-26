#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top element
 * @n: pointer
 * @line_n: line number
 */
void sub(stack_t **n, unsigned int line_n)
{
	int result;

	if (*n == NULL || (*n)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	result = (*n)->next->n - (*n)->n;

	pop(n, line_n);
	(*n)->n = result;
}

