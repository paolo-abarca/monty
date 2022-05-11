#include "main.h"

/**
 * _push - The opcode push pushes an element to the stack
 *
 * @stack: double pointer to the head of the stack
 * @line_number: is the line number
 * Return: void
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *num;
	char delimiter[] = " \t\n\r";

	num = strtok(NULL, delimiter);
	if (num == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = atoi(num);
	node->prev = NULL;
	node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = node;

	*stack = node;
}


/**
 * _pall - The opcode pall prints all the values on the stack
 *
 * @stack: double pointer to the head of the stack
 * @line_number: is the line number
 * Return: void
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * _pint - The opcode pint prints the value at the top of the stack
 *
 * @stack: double pointer to the head of the stack
 * @line_number: is the line number
 * Return: void
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
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
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	free(temp);
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
	stack_t *temp;

	if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;

	(*stack)->prev = temp;
	(*stack)->next = temp->next;

	temp->prev = NULL;

	if (temp->next != NULL)
		temp->next->prev = *stack;

	temp->next = *stack;

	*stack = temp;
}
