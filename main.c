#include "monty.h"

bus_t SUBB = {NULL, NULL, NULL, 0};

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *content = NULL;
    size_t size = 0;
    ssize_t read_line = 0;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    SUBB.file = file;

    while ((read_line = getline(&content, &size, file)) != -1)
    {
        SUBB.content = content;
        counter++;

        if (read_line > 0 && content[0] != '\n' && content[0] != '#')
        {
            execute(content, &stack, counter, file);
        }
    }

    free(content);
    free_stack(stack);
    fclose(file);

    return 0;
}
