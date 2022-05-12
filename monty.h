#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct settings_s - settings for all the program
 * @file: file
 * @line: line
 * @stack: stack
 * @queue: false
 */
typedef struct settings_s
{
	FILE *file;
	char *line;
	stack_t *stack;
	bool queue;
} settings_t;

/* Global Variable */
extern settings_t settings;
settings_t settings;

/* Helpers_functions */
void init_settings(void);
void check_args(int argc);
void open_file(char *f);
void get_operator(stack_t **stack, char *opcode, int line_number);
void free_code(void);

/* Error_handler */
void error_handler(char *opcode, int errorcode, int ln);

/* Tools */
int is_number(char *c);

/* Stack Management */
stack_t *push_stack(stack_t **head, const int n);
stack_t *push_queue(stack_t **head, const int n);
void free_stack(stack_t *head);

/* Operators_1 */
void _pall(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);

/* Operators_2 */
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

/* Operators_3 */
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);

/* Operators_4 */
void _stack(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
