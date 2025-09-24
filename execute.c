#include "monty.h"

/**
 * handle_push - validates and executes push
 * @stack: pointer to top of stack
 * @line_number: line number in file
 */
void handle_push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int i = 0, value;

	arg = strtok(NULL, " \t\n");
	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (arg[0] == '-')
		i++;
	for (; arg[i] != '\0'; i++)
	{
		if (!isdigit(arg[i]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	value = atoi(arg);
	push(stack, value, line_number);
}

/**
 * execute_instruction - executes Monty bytecode instructions
 * @stack: pointer to top of stack
 * @line: current line
 * @line_number: line number in file
 */
void execute_instruction(stack_t **stack, char *line, unsigned int line_number)
{
	char *opcode;

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return;

	if (strcmp(opcode, "push") == 0)
		handle_push(stack, line_number);
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		;
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
