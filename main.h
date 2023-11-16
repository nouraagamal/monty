#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void open(char *file_name);
int parse(char *buffer, int line_number, int format);
void _read(FILE *);
int length(FILE *);
void find(char *, char *, int, int);

stack_t *create(int n);
void _free(void);
void printstack(stack_t **, unsigned int);
void addstack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);
void call(op_func, char *, char *, int, int);

void printtop(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void _swap(stack_t **, unsigned int);

void _add(stack_t **, unsigned int);
void _sub(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void _mul(stack_t **, unsigned int);
void _mod(stack_t **, unsigned int);

void printchar(stack_t **, unsigned int);
void printstr(stack_t **, unsigned int);
void rotateleft(stack_t **, unsigned int);

void err(int error_code, ...);
void moreerr(int error_code, ...);
void stringerr(int error_code, ...);
void rotateright(stack_t **, unsigned int);
#endif
