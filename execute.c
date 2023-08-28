#include "monty.h"

/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 * @content: line content
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
    instruction_t opst[] = {
        {"push", monty_push}, {"pall", monty_pall}, {"pint", monty_pint},
        {"pop", monty_pop},
        {"swap", monty_swap},
        {"add", monty_add},
        {"nop", monty_nop},
        {"sub", monty_sub},
        {"div", monty_div},
        {"mul", monty_mul},
        {"mod", monty_mod},
        {"pchar", monty_pchar},
        {"pstr", monty_pstr},
        {"rotl", monty_rotl},
        {"rotr", monty_rotr},
        {"queue", monty_queue},
        {"stack", monty_stack},
        {NULL, NULL}
    };
    unsigned int a = 0;
    char *opp;

    opp = strtok(content, " \n\t");
    if (opp && opp[0] == '#')
        return 0;
    SUBB.arg = strtok(NULL, " \n\t");
    while (opst[a].opcode && opp)
    {
        if (strcmp(opp, opst[a].opcode) == 0)
        {
            opst[a].f(stack, counter);
            return 0;
        }
        a++;
    }
    if (opp && opst[a].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, opp);
        fclose(file);
        free(content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    return 1;
}
