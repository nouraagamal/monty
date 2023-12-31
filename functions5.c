#include "main.h"

/**
 * open - opens a file
 * @file_name: the file namepath
 * Return: nothing
 */
void open(char *file_name)
{
	FILE *file = fopen(file_name, "r");

	if (file_name == NULL || file == NULL)
		err(2, file_name);
	_read(file);
	fclose(file);
}

/**
 * _read - reads a file
 * @fd: pointer to file descriptor
 * Return: nothing
 */
void _read(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
		format = parse(buffer, line_number, format);
	free(buffer);
}

/**
 * parse - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int parse(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);
	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	find(opcode, value, line_number, format);
	return (format);
}

/**
 * find - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: nothing
 */
void find(char *opcode, char *value, int ln, int format)
{
	int i;
	int fl;

	instruction_t func_list[] = {
		{"push", addstack},
		{"pall", printstack},
		{"pint", printtop},
		{"pop", pop},
		{"nop", nop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", printchar},
		{"pstr", printstr},
		{"rotl", rotateleft},
		{"rotr", rotateright},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	for (fl = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call(func_list[i].f, opcode, value, ln, format);
			fl = 0;
		}
	}
	if (fl == 1)
		err(3, ln, opcode);
}

/**
 * call - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: nothing
 */
void call(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int fl;
	int i;

	fl = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			fl = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create(atoi(val) * fl);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
