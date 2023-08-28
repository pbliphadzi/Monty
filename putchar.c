#include "monty.h"

/**
 * monty_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void monty_pchar(stack_t **head, unsigned int counter)
{
    stack_t *top_node = *head;

    if (!top_node)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
        fclose(SUBB.file);
        free(SUBB.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    if (top_node->n > 127 || top_node->n < 0)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
        fclose(SUBB.file);
        free(SUBB.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", top_node->n);
}
