#include "main.h"

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
}















int (*convers(const char *fmt))(va_list)
{
	instructions_t check[] = {
		{"push", push},
		{"pall", pall}
		{NULL, NULL}
	};

	int i;

	for (i = 0 ; check[i].s; i++)
	{
		if (*fmt == *(check[i].s))
			break;
	}
	return (check[i].f);
}