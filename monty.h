#ifndef MONTY_H
#define MONTY_H
#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct bus_s
{
    char *arg;
    FILE *file;
    char *content;
    int lifi;
} bus_t;

extern bus_t SUBB;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char *clean_line(char *content);
void monty_push(stack_t **head, unsigned int number);
void monty_pall(stack_t **head, unsigned int number);
void monty_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void monty_pop(stack_t **head, unsigned int counter);
void monty_swap(stack_t **head, unsigned int counter);
void monty_add(stack_t **head, unsigned int counter);
void monty_nop(stack_t **head, unsigned int counter);
void monty_sub(stack_t **head, unsigned int counter);
void monty_div(stack_t **head, unsigned int counter);
void monty_mul(stack_t **head, unsigned int counter);
void monty_mod(stack_t **head, unsigned int counter);
void monty_pchar(stack_t **head, unsigned int counter);
void monty_pstr(stack_t **head, unsigned int counter);
void monty_rotl(stack_t **head, unsigned int counter);
void monty_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void monty_queue(stack_t **head, unsigned int counter);
void monty_stack(stack_t **head, unsigned int counter);

#endif
