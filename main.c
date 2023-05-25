#include <stdio.h>
#include "monty.h"

/**
 * main - opens monty file and reads lines
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 success, 1 failure
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	size_t n = 0;
	char *buf = NULL;
	char *token = NULL;
	int count = 0;
	ssize_t byte;
	stack_t *head = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fp = fopen(argv[1], "r");
		if (fp == NULL)
		{
			printf("Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			while ((byte = getline(&buf, &n, fp)) != -1)
			{
				count++;
				token = strtok(buf, " \t\n");
				if (token != NULL && token[0] != '#')
					get_func(token, &head, count);
			}
			free(buf);
			free_stack(head);
			fclose(fp);
		}
	}
	return (0);
}
