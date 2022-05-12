#include "monty.h"

/**
 * error_handler - is a function that handles errors
 *
 * @op: opcode generates error
 * @errorcode: the number of the error
 * @ln: is the line number
 * Return: void
 */

void error_handler(char *op, int errorcode, int ln)
{
	if (errorcode == -95)
	{dprintf(STDERR_FILENO, "L%u: can't %s an empty stack\n", ln, op);
		free_code();
		exit(EXIT_FAILURE);
	}
	if (errorcode == -96)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", op);
		exit(EXIT_FAILURE);
	}
	if (errorcode == -97)
	{
		dprintf(STDERR_FILENO, "Error: %s failed\n", op);
		free_code();
		exit(EXIT_FAILURE);
	}
	if (errorcode == -98)
	{
		dprintf(STDERR_FILENO, "L%u: can't %s, stack empty\n", ln, op);
		free_code();
		exit(EXIT_FAILURE);
	}
	if (errorcode == -99)
		dprintf(STDERR_FILENO,
		"L%u: can't %s, stack too short\n", ln, op), free_code(), exit(EXIT_FAILURE);
	if (errorcode == -126)
		dprintf(STDERR_FILENO,
		"L%u: division by zero\n", ln), free_code(), exit(EXIT_FAILURE);
	if (errorcode == -127)
		dprintf(STDERR_FILENO,
		"L%u: can't %s, value out of range\n", ln, op),
free_code(), exit(EXIT_FAILURE);
	if (errorcode == -128)
		dprintf(STDERR_FILENO,
		"L%d: unknown instruction %s\n", ln, op), free_code(), exit(EXIT_FAILURE);
	if (errorcode == -129)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", ln);
		free_code();
		exit(EXIT_FAILURE); }
}
