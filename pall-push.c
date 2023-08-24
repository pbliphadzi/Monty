#include "monty.h"


void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;  
    stack_t *current;
   *current = *stack; 

    if (*stack == NULL)
    {
        return;
    }
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * push - add element to the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
 void push(stack_t **stack, unsigned int line_number)
{
    char *str = strtok(NULL, " ");

    if (str == NULL || str[0] == '\0')
    {
        fprintf(stderr, "L%u: usage - Push <int>\n", line_number);
        exit(EXIT_FAILURE);
    }

    char *ptr_end;
    int value = strtol(str, &ptr_end, 10);

    if (*ptr_end != '\0' && !isspace(*ptr_end))
    {
        fprintf(stderr, "L%u: usage - Push <int>\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "malloc failure\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
    {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

