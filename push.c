#include "monty.h"

/**
 * monty_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void monty_push(stack_t **head, unsigned int counter)
{
    int y, j = 0, flag = 0;

    if (!SUBB.arg)
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(SUBB.file);
        free(SUBB.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    if (SUBB.arg[0] == '-')
        j++;

    while (SUBB.arg[j] != '\0')
    {
        if (SUBB.arg[j] > '9' || SUBB.arg[j] < '0')
        {
            flag = 1;
            break;
        }
        j++;
    }

    if (flag == 1)
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(SUBB.file);
        free(SUBB.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    y = atoi(SUBB.arg);

    if (SUBB.lifi == 0)
        addnode(head, y);
    else
        addqueue(head, y);
}
