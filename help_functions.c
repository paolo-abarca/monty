#include "monty.h"

/**
 * init_settings - function that initializes the settings
 *
 * Return: void
 */

void init_settings(void)
{
	settings.file = NULL;
	settings.line = NULL;
	settings.stack = NULL;
	settings.queue = false;
}

/**
 * check_args - check if the program receives 2 arguments
 *
 * @argc: is the argument counter
 * Return: void
 */

void check_args(int argc)
{
	if (argc > 2 || argc < 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * open_file - function in charge of opening files
 *
 * @f: the name of the file
 * Return: void
 */

void open_file(char *f)
{
	unsigned int line_number = 1;
	ssize_t read;
	size_t len = 0;
	char *token, *val, *opcode;
	int value;

	settings.file = fopen(f, "r");
	if (settings.file == NULL)
		error_handler(f, -96, line_number);
	while ((read = getline(&settings.line, &len, settings.file)) != -1)
	{
		token = strtok(settings.line, " ");
		if (*token == '#' || *token == '\n')
		{
			line_number++;
			continue;
		}
		val = strtok(NULL, " \n");
		opcode = strtok(token, " \n");
		if (strcmp(opcode, "push") == 0)
		{
			if (is_number(val) && val != NULL)
			{
				value = atoi(val);
				if (!settings.queue)
					push_stack(&settings.stack, value);
				else
					push_queue(&settings.stack, value);
			}
			else
				error_handler(opcode, -129, line_number);
		} else
		{
			get_operator(&settings.stack, opcode, line_number);
		}
		line_number++;
	}
}

/**
 * get_operator - get stack operators
 *
 * @stack: The pointer to the head of the stack
 * @opcode: is the instruction
 * @line_number: is the line number
 * Return: void
 */

void get_operator(stack_t **stack, char *opcode, int line_number)
{
	int i;
	char *op;
	instruction_t ops[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"nop", _nop},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	op = strtok(opcode, " \n");
	for (i = 0; ops[i].opcode; i++)
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
	error_handler(opcode, -128, line_number);
}

/**
 * free_code - free code
 *
 * Return: void
 */

void free_code(void)
{
	fclose(settings.file);
	free(settings.line);
	free_stack(settings.stack);
}
