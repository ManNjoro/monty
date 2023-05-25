#include "monty.h"

/**
 * push - pushes an element into a stack
 * @n: a double pointer
 * @line_n: data to be pushed
 * Return: void
 */
void push(stack_t **n, unsigned int line_n)
{
	stack_t *new_node;

	(void)line_n;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = global_var;
	new_node->prev = NULL;

	if (*n == NULL)
	{
		new_node->next = NULL;
		*n = new_node;
	}
	new_node->next = *n;
	(*n)->prev = new_node;
	*n = new_node;
}

/**
 * pall - prints all elements in a stack
 * @n: pointer
 * @line_n: line number
 * Return: void
 */

void pall(stack_t **n, unsigned int line_n)
{
	stack_t *temp;

	(void)line_n;
	temp = *n;

	if ((*n) == NULL || n == NULL)
		return;
	while (temp != NULL)
	{
		printf("%d", temp->n);
		temp = temp->next;
	}
}

/**
 * get_func - matches opcode from input to existing opcode in struct
 * @op: character to check
 * @stack: stack
 * @line_number: line number
 *
 * Return: the pointer to the appropriate function or NULL if nothing matches
 */

void get_func(char *op, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push_func},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
	};
	int i = 0;

	while (find_op[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, op) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}

/**
 * pint - prints the top element of stack
 * @n: pointer
 * @line_n: line num
 * Return: void
 */
void pint(stack_t **n, unsigned int line_n)
{
	if (*n == NULL || n == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	printf("%d", (*n)->n);
}

/**
 * pop - removes top element of stack
 * @n: pointer
 * @line_n: ..
 * Return: void
 */
void pop(stack_t **n, unsigned int line_n)
{
	stack_t *temp;

	if (*n == NULL || n == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_n);
		exit(EXIT_FAILURE);
	}
	temp = *n;
	*n = (*n)->next;
	if (*n != NULL)
		(*n)->prev = NULL;
	free(temp);
}
