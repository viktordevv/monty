#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short" , line_number);
        exit(EXIT_FAILURE);
    }

    stack_t tmp = *stack;
    tmp->next->n = tmp->n + tmp->next->n;

    pop(stack, line_number);
}

void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}