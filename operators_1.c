#include "monty.h"

/**
 * _pall - The opcode pall prints all the values on the stack
 *
 * @stack: Double pointer to the head of the stack
 * @line_number: is the line number
 * Return: void
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	if (!stack || !(*stack))
		return;

	tmp = *stack;

	while (tmp->prev)
		tmp = tmp->prev;

	for (; tmp->next; tmp = tmp->next)
		printf("%d\n", tmp->n);

	printf("%d\n", tmp->n);
}

/**
 * _pint - The opcode pint prints the value at the top of the stack
 *
 * @stack: Double pointer to the head of the stack
 * @line_number: is the line number
 * Return: void
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack;

	actual == NULL ? error_handler("pint", -98, line_number) : (void) actual;
	printf("%d\n", actual->n);
}

/**
 * _pop - The opcode pop removes the top element of the stack
 *
 * @stack: double pointer to the head of the stack
 * @line_number: is the line number
 * Return: void
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	tmp == NULL ? error_handler("pop", -95, line_number) : (void) tmp;
	*stack = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;

	free(tmp);
}

/**
 * _swap - The opcode swap swaps the top two elements of the stack
 *
 * @stack: double pointer to the head of the stack
 * @line_number: is the line number
 * Return: void
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int aux;
	stack_t *actual = *stack, *next;

	actual == NULL || actual->next == NULL ?
	error_handler("swap", -99, line_number) : (void) actual;
	next = actual->next;
	aux = actual->n;
	actual->n = next->n;
	next->n = aux;
}

/**
 * _nop - The opcode nop doesn't do anything
 *
 * @stack: double pointer to the head of the stack
 * @line_number: is the line number
 * Return: void
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
