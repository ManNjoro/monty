#include "monty.h"

/**
 * push - pushes an element into a stack
 * @n: a double pointer
 * @line_n: data to be pushed
 * Return: void
 */
void push(stack_t **n, unsigned int line_n)
{
	(void)line_n;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = global_var;
	new_node->next = NULL;

	if (*n == NULL)
	{
		*n = new_node;
	}
	new_node->prev = *n;
	(*n)->next = new_node;
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

	(void)line_n
	temp = *n;
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
	instruction_t find_op[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int index = 0;

	while (find_op[index].opcode != NULL)
	{
		if (strcmp(find_op[index].opcode, op) == 0)
		{
			find_op[index].f(stack, line_number);
			return;
		}
		index++;
	}
	printf("L%d: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}
