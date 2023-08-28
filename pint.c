#include "monty.h"

/**
 * monty_pint - prints the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void monty_pint(stack_t **head, unsigned int counter)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
        fclose(SUBB.file);
        free(SUBB.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*head)->n);
}
