#define  _POSIX_C_SOURCE 200809L
#include "monty.h"
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack;
	char *line;
	size_t len = 0;
	unsigned int line_number = 0;

	/* Check for the correct number of command-line arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* Open the Monty byte code file for reading */
	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Initialize the stack and other variables */
	stack = NULL;
	line = NULL;

	/* Read and process each line of the Monty byte code file */
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		execute_instruction(&stack, line, line_number);
	}

	/* Free allocated memory and close the file */
	free(line);
	fclose(file);
	free_stack(&stack);

	return (EXIT_SUCCESS);
}
