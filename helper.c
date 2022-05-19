#include "monty.h"
#include <ctype.h>

/**
 * isNumber - Identify if a string is a number
 *
 * @s: String for checking
 * Return: ! if is a number 0 if is not.
 */

int isNumber(char *s)
{
	int i;

	for (i = 0; s[i] != '\n' && s[i]; i++)
	{
		if ((isdigit(s[i]) == 0) && s[i] != '-')
			return (0);
	}
	return (1);
}

/**
 * mod - Modulus of two numbers
 *
 * @stack: Pointer to stack
 * @line_number: line numbers
 * Return: void.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int m;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	m = (*stack)->n;
	if (m == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
	(*stack)->n %= m;
}
