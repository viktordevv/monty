#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{

    char *value = strtok(token, " \t");

    stack_t *new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        fprintf(stderr, "L%d: can't malloc\n", line_number);
        exit(EXIT_FAILURE);
    }
    new->n = atoi(value);
    new->next = *stack;
    new->prev = NULL;
    if (*stack != NULL)
    {
        (*stack)->prev = new;
    }
    *stack = new;
}