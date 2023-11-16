#include "main.h"

/**
 * printchar - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 * Return: nothing
 */
void printchar(stack_t **stack, unsigned int line_number)
{
	int asc;

	if (stack == NULL || *stack == NULL)
		stringerr(11, line_number);
	asc = (*stack)->n;
	if (asc < 0 || asc > 127)
		stringerr(10, line_number);
	printf("%c\n", asc);
}

/**
 * printstr - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 * Return: nothing
 */
void printstr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int asc;
	stack_t *x;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	x = *stack;
	while (x != NULL)
	{
		asc = x->n;
		if (asc <= 0 || asc > 127)
			break;
		printf("%c", asc);
		x = x->next;
	}
	printf("\n");
}

/**
 * rotateleft - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 * Return: nothing
 */
void rotateleft(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *x;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	x = *stack;
	while (x->next != NULL)
		x = x->next;
	x->next = *stack;
	(*stack)->prev = x;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotateright - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 * Return: nothing
 */
void rotateright(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *x;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	x = *stack;
	while (x->next != NULL)
		x = x->next;
	x->next = *stack;
	x->prev->next = NULL;
	x->prev = NULL;
	(*stack)->prev = x;
	(*stack) = x;
}
