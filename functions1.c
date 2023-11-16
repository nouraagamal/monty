#include "main.h"

/**
 * addstack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 * Return: nothing
 */
void addstack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *x;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	x = head;
	head = *new_node;
	head->next = x;
	x->prev = head;
}

/**
 * printstack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 * Return: nothing
 */
void printstack(stack_t **stack, unsigned int line_number)
{
	stack_t *x;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	x = *stack;
	while (x)
	{
		printf("%d\n", x->n);
		x = x->next;
	}
}

/**
 * pop - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *x;

	if (stack == NULL || *stack == NULL)
		moreerr(7, line_number);
	x = *stack;
	*stack = x->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(x);
}

/**
 * printtop - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 * Return: nothing
 */
void printtop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		moreerr(6, line_number);
	printf("%d\n", (*stack)->n);
}
