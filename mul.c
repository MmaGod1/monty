#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the head of the stack
 * @line_number: current line number in the Monty file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
