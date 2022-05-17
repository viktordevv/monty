#include "monty.h"

void free_stack(stack_t *head)
{
	if (head == NULL)
		return;

	while (head)
	{
		stack_t *next = head->next;

		free(head);
		head = next;
	}
}