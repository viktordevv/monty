#include "monty.h"

void checker(stack_t **stack, unsigned int line_number);
{

    instruction_t opcode[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}};

    int i = 0;
    while (opcode[i].opcode != NULL)
    {
        if (strcmp(opcode[i].opcode, token) == 0)
        {
            opcode[i].f(stack, line_number);
            return;
        }
        i++;
    }
    fprintf(stderr, "L%d: unknown instruction %s", line_number, token);
    exit(EXIT_FAILURE);
}
