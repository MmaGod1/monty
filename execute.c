#include "monty.h"

/**
 * execute_instruction - executes monty bytecode instructions
 * @stack: Pointer to the top of the stack.
 * @line: Line containing the Monty bytecode instruction
 * @line_number: Current line number in the Monty bytecode file
 * Return: void
 */
void execute_instruction(stack_t **stack, char *line, unsigned int line_number)
{
	char *opcode;
	char *arg;
	int i = 0, value;

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return;

	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \t\n");
		if (arg == NULL)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		/* Validate integer (allow negative numbers) */
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
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		/* do nothing */
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
