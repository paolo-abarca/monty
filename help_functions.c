#include "monty.h"

/**
 * open_file - function in charge of opening files
 *
 * @file: the name of the file
 * @stack: double pointer to top of the stack
 * Return: error if I fail in code or close the file
 */

void open_file(char *file, stack_t **stack)
{
	FILE *fd;
	char *string = NULL;
	size_t string_size = 0;
	char *token;
	char delimiter[] = " \t\n\r";
	unsigned int num = 0;

	fd = fopen(file, "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	while (getline(&string, &string_size, fd) != EOF)
	{
		token = strtok(string, delimiter);
		num++;

		if (token != NULL)
			get_operator(stack, token, num);
	}

	if (string != NULL)
		free(string);

	fclose(fd);
}

/**
 * get_operator - get stack operators
 *
 * @stack: the pointer to the head of the stack
 * @op: is the instruction
 * @line_number: is the line number
 * Return: void
 */

void get_operator(stack_t **stack, char *op, unsigned int line_number)
{
	int i;
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"nop", _nop},
		{"add", _add},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
	}

	if (strlen(op) != 0 && op[0] != '#')
	{
		printf("L%u: unknown instruction %s\n", line_number, op);
		exit(EXIT_FAILURE);
	}
}
