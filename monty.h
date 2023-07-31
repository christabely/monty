#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked structure implementation
 * @n: integer
 * @prev: backward pointer of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: a doubly linked list node structure
 * for stack, queues, LIFO, FIFO project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
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
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void push_stack(stack_t **h, unsigned int number);
void display_stack(stack_t **h, unsigned int number);
void printstack_top(stack_t **h, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void freestack(stack_t *h);
void pop_element(stack_t **h, unsigned int counter);
void swap_stack(stack_t **h, unsigned int counter);
void add_stack(stack_t **h, unsigned int counter);
void stack_nop(stack_t **h, unsigned int counter);
void sub_stack(stack_t **h, unsigned int counter);
void divide_stack(stack_t **h, unsigned int counter);
void smul(stack_t **h, unsigned int counter);
void _modulo(stack_t **h, unsigned int counter);
void pchar(stack_t **h, unsigned int counter);
void _cpstr(stack_t **h, unsigned int counter);
void move_top(stack_t **h, unsigned int counter);
void _crotr(stack_t **h, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **h, int n);
void addqueue(stack_t **h, int n);
void _cqueue(stack_t **h, unsigned int counter);
void out_stack(stack_t **h, unsigned int counter);
#endif
