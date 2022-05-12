#include "monty.h"

/**
 * main - Entry point
 *
 * @argc: Are the arguments we give to the program
 * @argv: Are the test files
 * Return: Always EXIT_SUCCESS
 */

int main(int argc, char **argv)
{
	init_settings();
	check_args(argc);
	open_file(*(argv + 1));
	free_code();

	return (EXIT_SUCCESS);
}
