#include "monty.h"

/**
 * pstr - prints the string starting from the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: current line number in the Monty file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
