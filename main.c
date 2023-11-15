#include "main.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open(argv[1]);
	_free();
	return (0);
}

/**
 * create - Creates a node.
 * @n: Number to go inside the node.
 * Return: a pointer to the node. Otherwise NULL.
 */
stack_t *create(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * _free - Frees nodes in the stack.
 * Return: nothing
 */
void _free(void)
{
	stack_t *x;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		x = head;
		head = head->next;
		free(x);
	}
}

/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to new node.
 * @ln: line number of the opcode.
 * Return: nothing
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (x->next != NULL)
		x = x->next;
	x->next = *new_node;
	(*new_node)->prev = x;
}
