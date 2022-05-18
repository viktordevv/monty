#include "monty.h"

/**
 * push - push an element to the stack
 * @stack : pointer
 * @line_number : line number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "L%d: can't malloc\n", line_number);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(token);
	new->next = *stack;
	new->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * pall - push an element to the stack
 * @stack : pointer
 * @line_number : line number
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;

	if (*stack == NULL)
		return;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - push an element to the stack
 * @stack : pointer
 * @line_number : line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - push an element to the stack
 * @stack : pointer
 * @line_number : line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
}

/**
 * swap - push an element to the stack
 * @stack : pointer
 * @line_number : line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
	{
		tmp->next->prev = *stack;
	}
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
}
