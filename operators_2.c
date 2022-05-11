#include "monty.h"

/**
 * _nop - The opcode nop doesn’t do anything
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

/**
 * _add - The opcode add adds the top two elements of the stack
 *
 * @stack: double pointer to the head of the stack
 * @line_number: is the line number
 * Return: void
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	sum = temp->n + temp->next->n;
	temp->next->n = sum;

	*stack = temp->next;

	free(temp);
}
