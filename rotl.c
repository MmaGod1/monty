#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the head of the stack
 * @line_number: current line number in the Monty file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void) line_number; /* unused */

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	last = *stack;

	while (last->next != NULL)
		last = last->next;

	*stack = first->next;
	(*stack)->prev = NULL;

	last->next = first;
	first->prev = last;
	first->next = NULL;
}
