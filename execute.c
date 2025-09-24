#include "monty.h"
/**
 * execute_instruction - executes monty bytecode instructions
 * @stack: Pointer to the top of the stack.
 * @line: Line containing the Monty bytecode instruction
 * @line_number: Current line number in the Monty bytecode file
 * Return: void.
 */

void execute_instruction(stack_t **stack, char *line, unsigned int line_number)
{
	char opcode[100];
	int arg;

	/* Parse the instruction from the line */
	if (sscanf(line, " %99s %d", opcode, &arg) == 2)
	{
		if (strcmp(opcode, "push") == 0)
		{
			push(stack, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack, line_number);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp(line, "nop\n") != 0)
	{
		fprintf(stderr, "L%d: invalid instruction format\n", line_number);
		exit(EXIT_FAILURE);
	}
}
