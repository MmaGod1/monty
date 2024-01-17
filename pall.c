#include "monty.h"
/**
 * pall - print all values on the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	/* Implement pall opcode */
	(void)line_number;
	/* Unused parameter */
	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
