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
	size_t len;
	ssize_t read_line;
	unsigned int num = 0;
	char *line = NULL;
	FILE *fd;
	char *command;

	fd = fopen(file, "r");
	if (!fd)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	while ((read_line = getline(&line, &len, fd)) != -1)
	{
		command = strtok(line, DELIMS);
		num++;

		if (command)
			get_operator(stack, command, num);
	}

	if (line)
		free(line);

	fclose(fd);
}

/**
 * get_operator - get stack operators
 *
 * @stack: the pointer to the head of the stack
 * @op: is the instruction
 * @line_num: is the line number
 * Return: void
 */

void get_operator(stack_t **stack, char *op, unsigned int line_num)
{
	int i;
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode; i++)
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_num);
			return;
		}

	if (strlen(op) != 0 && op[0] != '#')
	{
		printf("L%u: unknown instruction %s\n", line_num, op);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_glob - global frees memory
 *
 * Return: void
 */

void free_glob(void)
{
	stack_t *to_free;
	stack_t *temp = NULL;

	to_free = *global_head;

	while (to_free)
	{
		temp = to_free->next;

		free(to_free);

		to_free = temp;
	}
}
