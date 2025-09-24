#include "monty.h"
/**
 * push - pushes an element onto the stack
 * @stack: double pointer to the head of the stack
 * @value: integer value to push
 * @line_number: line number in the file (for error messages)
 *
 * Return: void
 */
void push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new, *last;

	(void) line_number;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->prev = NULL;
	new->next = NULL;

	if (*stack == NULL)
	{
		*stack = new;
		return;
	}

	if (mode == STACK) /* LIFO: add to top */
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	else /* QUEUE: add to bottom */
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}
