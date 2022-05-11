#include "monty.h"
/**
 * exec_add - this function executes the add opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void exec_add(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *next;

	if (actual == NULL || actual->next == NULL)
		error_handler("add", -99, line_number);
	next = actual->next;
	next->n =  next->n + actual->n;
	exec_pop(stack, line_number);
}
