#include "monty.h"

/**
 * _stack - this function executes the stack opcode
 *
 * @stack: the stack to read the numbers
 * @line_number: is the line number
 * Return: void
 */

void _stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	settings.queue = false;
}

/**
 * _queue - this function executes the queue opcode
 *
 * @stack: the stack to read the numbers
 * @line_number: is the line number
 * Return: void
 */

void _queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	settings.queue = true;
}
