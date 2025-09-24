#include "monty.h"

/**
 * stack - sets mode to stack (LIFO)
 * @stack: double pointer to head of stack
 * @line_number: line number
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	mode = STACK;
}
