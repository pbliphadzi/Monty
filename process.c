#include "monty.h"

/**
 * monty_stack - sets the mode to stack (LIFO)
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void monty_stack(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    SUBB.lifi = 0;
}


/**
 * monty_div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void monty_div(stack_t **head, unsigned int counter)
{
    stack_t *top_node;
    int len = 0, aux;

    top_node = *head;
    while (top_node)
    {
        top_node = top_node->next;
        len++;
    }

    if (len < 2)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", counter);
        fclose(SUBB.file);
        free(SUBB.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    top_node = *head;

    if (top_node->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(SUBB.file);
        free(SUBB.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    aux = top_node->next->n / top_node->n;
    top_node->next->n = aux;
    *head = top_node->next;
    free(top_node);
}

/**
 * monty_sub - performs subtraction of top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void monty_sub(stack_t **head, unsigned int counter)
{
    stack_t *aux;
    int sbtr, nodes;

    aux = *head;
    for (nodes = 0; aux != NULL; nodes++)
        aux = aux->next;

    if (nodes < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
        fclose(SUBB.file);
        free(SUBB.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    aux = *head;
 sbtr = aux->next->n - aux->n;
    aux->next->n = sbtr;
    *head = aux->next;
    free(aux);
}

/**
 * monty_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void monty_add(stack_t **head, unsigned int counter)
{
    stack_t *top_node, *next_node;
    int num_nodes = 0, sum;

    top_node = *head;

    while (top_node)
    {
        top_node = top_node->next;
        num_nodes++;
    }

    if (num_nodes < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);
        fclose(SUBB.file);
        free(SUBB.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    top_node = *head;
    next_node = top_node->next;

    sum = top_node->n + next_node->n;
    next_node->n = sum;

    *head = next_node;
    free(top_node);
}

/**
 * monty_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void monty_mul(stack_t **head, unsigned int counter)
{
    stack_t *top_node, *next_node;
    int num_nodes = 0, product;

    top_node = *head;

    while (top_node)
    {
        top_node = top_node->next;
        num_nodes++;
    }

    if (num_nodes < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
        fclose(SUBB.file);
        free(SUBB.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    top_node = *head;
    next_node = top_node->next;

    product = next_node->n * top_node->n;
    next_node->n = product;

    *head = next_node;
    free(top_node);
}

/**
 * monty_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void monty_mod(stack_t **head, unsigned int counter)
{
    stack_t *top_node, *next_node;
    int num_nodes = 0, remainder;

    top_node = *head;

    while (top_node)
    {
        top_node = top_node->next;
        num_nodes++;
    }

    if (num_nodes < 2)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
        fclose(SUBB.file);
        free(SUBB.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    top_node = *head;
    next_node = top_node->next;

    if (top_node->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(SUBB.file);
        free(SUBB.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    remainder = next_node->n % top_node->n;
    next_node->n = remainder;

    *head = next_node;
    free(top_node);
}


/**
 * monty_pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void monty_pstr(stack_t **head, unsigned int counter)
{
    stack_t *top_node;
    (void)counter;

    top_node = *head;

    while (top_node)
    {
        if (top_node->n > 127 || top_node->n <= 0)
        {
            break;
        }
        printf("%c", top_node->n);
        top_node = top_node->next;
    }

    printf("\n");
}
/**
 * monty_nop - does nothing
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void monty_nop(stack_t **head, unsigned int counter)
{
    (void)counter;
    (void)head;
}
/**
 * monty_pall - prints the stack
 * @head: stack head
 * @counter: not used
 * Return: no return
 */
void monty_pall(stack_t **head, unsigned int counter)
{
    stack_t *current_node;
    (void)counter;

    current_node = *head;
    
    while (current_node)
    {
        printf("%d\n", current_node->n);
        current_node = current_node->next;
    }
}

/**
 * monty_pop - removes the top element from the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void monty_pop(stack_t **head, unsigned int counter)
{
    stack_t *top_node;

    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
        fclose(SUBB.file);
        free(SUBB.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    top_node = *head;
    *head = top_node->next;
    free(top_node);
}

/**
 * monty_rotr - rotates the stack to the bottom
 * @head: stack head
 * @counter: line_number (unused)
 * Return: no return
 */
void monty_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *copy;

    copy = *head;

    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    while (copy->next)
    {
        copy = copy->next;
    }

    copy->next = *head;
    copy->prev->next = NULL;
    copy->prev = NULL;
    (*head)->prev = copy;
    (*head) = copy;
}

/**
 * monty_rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line_number (unused)
 * Return: no return
 */
void monty_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *first_node = *head, *second_node;

    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    second_node = (*head)->next;
    second_node->prev = NULL;

    while (first_node->next != NULL)
    {
        first_node = first_node->next;
    }

    first_node->next = *head;
    (*head)->next = NULL;
    (*head)->prev = first_node;
    (*head) = second_node;
}
