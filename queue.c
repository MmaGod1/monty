#include "monty.h"

/**
 * queue - sets mode to queue (FIFO)
 * @stack: double pointer to head of stack
 * @line_number: line number
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	mode = QUEUE;
}
