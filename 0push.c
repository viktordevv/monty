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
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = stack;

    /* line number what for? */

    if (*stack == NULL)
        return;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}

void pint(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", *stack->n);
}