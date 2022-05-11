#include "monty.h"

/**
 * main - Entry point
 *
 * @argc: are the arguments we give to the program
 * @argv: are the test files
 * Return: always EXIT_SUCCESS
 */

int main(int argc, char *argv[])
{
	stack_t **head_glob;
	stack_t *head;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	head = NULL;
	head_glob = &head;

	open_file(argv[1], &head);

	atexit(free_glob);

	exit(EXIT_SUCCESS);
}
