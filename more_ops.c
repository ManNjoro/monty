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


/**
 * push_func - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number being executed
 */
void push_func(stack_t **stack, unsigned int line_number)
{
	int value;
	char *token;
	stack_t *new_node;

	token = strtok(NULL, " \t\n");
	if (token == NULL)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (is_number(token))
	{
		value = atoi(token);
		new_node = malloc(sizeof(stack_t));
		if (new_node == NULL)
		{
			printf("Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new_node->n = value;
		new_node->prev = NULL;
		if (*stack == NULL)
		{
			new_node->next = NULL;
			*stack = new_node;
		}
		else
		{
			new_node->next = *stack;
			(*stack)->prev = new_node;
			*stack = new_node;
		}
	}
	else
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}

