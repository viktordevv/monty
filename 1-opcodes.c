#include "monty.h"

/**
 * add - add two numbers
 * @stack : pointer
 * @line_number : line number
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int m;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	m = tmp->n + tmp->next->n;
	tmp->next->n = m;

	pop(stack, line_number);
}

/**
 * nop - push an element to the stack
 * @stack : pointer
 * @line_number : line number
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - Substract two numbers
 * @stack : pointer
 * @line_number : line number
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int m;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	m = tmp->next->n - tmp->n;
	tmp->next->n = m;

	pop(stack, line_number);
}

/**
 * _div - Divide two numbers
 * @stack : pointer
 * @line_number : line number
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int m;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	m = (*stack)->n;
	if (m == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
	(*stack)->n /= m;
}

/**
 * mul - Multiply two numbers
 * @stack : pointer
 * @line_number : line number
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int m;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	m = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n *= m;
}
