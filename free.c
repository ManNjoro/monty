#include "monty.h"

/**
 * free_stack - free a memory stack
 * @head: head of a stack
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * get_tokens - get tokens from line
 * @line: line from file
 * @line_number: line number
 *
 * Return: int
 */

char *get_tokens(char *line, unsigned int line_number)
{
	char delim[2] = "\n ";
	char *token = NULL;
	char *holder = NULL;

	token = strtok(line, delim);
	if (token == NULL)
		return (NULL);
	holder = strtok(NULL, delim);
	if (holder != NULL)
	{
		if (is_number(holder))
			global_var = atoi(holder);
		else
		{
			printf("L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else if (holder == NULL && strcmp(token, "push") == 0)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	return (token);
}
