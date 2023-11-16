#include "main.h"

/**
 * _mul - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 * Return: nothing
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		moreerr(8, line_number, "mul");
	(*stack) = (*stack)->next;
	s = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _mod - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 * Return: nothing
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		moreerr(8, line_number, "mod");
	if ((*stack)->n == 0)
		moreerr(9, line_number);
	(*stack) = (*stack)->next;
	s = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * err - Prints appropiate error messages determined by their error code.
 * @error_code: The error codes.
 * Return: nothing
 */
void err(int error_code, ...)
{
	va_list ag;
	char *op;
	int n;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			n = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", n, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	_free();
	exit(EXIT_FAILURE);
}

/**
 * moreerr - handles errors.
 * @error_code: The error codes.
 * Return: nothing
 */
void moreerr(int error_code, ...)
{
	va_list ag;
	char *op;
	int n;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			n = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", n, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	_free();
	exit(EXIT_FAILURE);
}

/**
 * stringerr - handles errors.
 * @error_code: The error codes.
 * Return: nothing
 */
void stringerr(int error_code, ...)
{
	va_list ag;
	int n;

	va_start(ag, error_code);
	n = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", n);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", n);
			break;
		default:
			break;
	}
	_free();
	exit(EXIT_FAILURE);
}
