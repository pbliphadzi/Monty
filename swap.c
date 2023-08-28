#include "monty.h"

/**
 * monty_swap - swaps the top two elements of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void monty_swap(stack_t **head, unsigned int counter)
{
    int temp; 

    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
        fclose(SUBB.file);
        free(SUBB.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    temp = (*head)->n; 
    (*head)->n = (*head)->next->n;
    (*head)->next->n = temp;
}
