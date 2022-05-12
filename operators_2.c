#include "monty.h"

/**
 * _add - The opcode add adds the top two elements of the stack
 *
 * @stack: double pointer to the head of the stack
 * @line_number: is the line number
 * Return: void
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *next;

	if (actual == NULL || actual->next == NULL)
		error_handler("add", -99, line_number);

	next = actual->next;
	next->n =  next->n + actual->n;
	_pop(stack, line_number);
}

/**
 * _sub - The op sub top element of the stack from the second top element
 *
 * @stack: double pointer to the head of the stack
 * @line_number: is the line number
 * Return: void
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *next;

	if (actual == NULL || actual->next == NULL)
		error_handler("sub", -99, line_number);
	next = actual->next;
	next->n =  next->n - actual->n;
	_pop(stack, line_number);
}

/**
 * _div - The div op splits the second element on the stack by the top element
 *
 * @stack: double pointer to the head of the stack
 * @line_number: is the line number
 * Return: void
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *next;

	if (actual == NULL || actual->next == NULL)
		error_handler("div", -99, line_number);
	if (actual->n == 0)
		error_handler("div", -126, line_number);
	next = actual->next;
	next->n =  next->n / actual->n;
	_pop(stack, line_number);
}

/**
 * _mul - The mul op multi second top element on the stack with top element
 *
 * @stack: double pointer to the head of the stack
 * @line_number: is the line number
 * Return: void
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *next;

	if (actual == NULL || actual->next == NULL)
		error_handler("mul", -99, line_number);
	next = actual->next;
	next->n =  next->n * actual->n;
	_pop(stack, line_number);
}

/**
 * _mod - The op mod remainder division of second top element on stack element
 *
 * @stack: double pointer to the head of the stack
 * @line_number: is the line number
 * Return: void
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *next;

	if (current == NULL || current->next == NULL)
		error_handler("mod", -99, line_number);
	if (current->n == 0)
		error_handler("mod", -126, line_number);
	next = current->next;
	next->n =  next->n % current->n;
	_pop(stack, line_number);
}
