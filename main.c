#include "monty.h"
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    stack_t *head = NULL;
    int line_number = 1;  /* ! fix line number */
    while ((read = getline(&line, &len, fp)) != -1)
    {
        char *token = strtok(line, " \n\t");
        if (token == NULL)
        {
            continue;
        }
        if (strcmp(token, "push") == 0)
        {
            token = strtok(NULL, " \n\t");
            if (token == NULL)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(&head, line_number);
        }
        else
        {
            checker(head, line_number);
        }
        line_number++;
    }
    free(line);
    fclose(fp);
    return (0);
}

