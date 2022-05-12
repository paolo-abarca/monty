#include "monty.h"

/**
 * _pchar - The pchar opcode prints the character on top of the stack
 *
 * @stack: the stack to read the numbers
 * @line_number: is the line number
 * Return: void
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack;

	actual == NULL ? error_handler("pchar", -98, line_number) : (void) actual;
	actual->n < 0 || actual->n > 127 ?
	error_handler("pchar", -127, line_number) : (void)actual;
	putchar(actual->n);
	putchar('\n');
}

/**
 * _pstr - The opcode pstr prints the string starting at the top of the stack
 *
 * @stack: the stack to read the numbers
 * @line_number: is the line number
 * Return: void
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack;
	(void) line_number;
	while (actual)
	{
		if ((actual->n > 0) && actual->n < 127)
		{
			putchar(actual->n);
			actual = actual->next;
		} else
			break;
	}
	putchar('\n');
}

/**
 * _rotl - The opcode rotl rotates the stack to the top
 *
 * @stack: the stack to read the numbers
 * @line_number: is the line number
 * Return: void
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *next;
	int aux;

	(void) line_number;
	if (actual != NULL)
	{
		next = actual->next;
		aux = actual->n;
		while (actual->next != NULL)
		{
			actual->n = next->n;
			actual = next;
			next = actual->next;
		}
		actual->n = aux;
	}
}

/**
 * _rotr - The opcode rotr rotates the stack to the bottom
 *
 * @stack: the stack to read the numbers
 * @line_number: is the line number
 * Return: void
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack;
	int aux;

	(void) line_number;

	if (actual != NULL && actual->next != NULL)
	{
		for (; actual->next; actual = actual->next)
			;

		aux = actual->n;
		(actual->prev)->next = NULL;
		free(actual);
		*stack = push_stack(&(*stack), aux);
	}
}
