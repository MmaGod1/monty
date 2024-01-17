#include "monty.h"

/**
 * push - push an element onto the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
int value;
char *argument_str;
stack_t *new_node;
    /* Implementation of push opcode */
    /* Check for usage error */
    if (*stack == NULL)
    {
    fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Get the integer argument */
    argument_str = strtok(NULL, " \n");
    if (!argument_str || !isdigit(*argument_str)) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Convert argument to integer and push onto the stack */
    value = atoi(argument_str);
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}
