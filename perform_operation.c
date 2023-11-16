#include "monty.h"

/**
 * perform_operation - executes monty file instructions.
 * @instruct_array: a NULL-terminated array of strings
 * representing a single instruction opcode [and arguments].
 */
void perform_operation(char *instruct_array[])
{
	opfunc ofunction;

	ofunction = find_opfunction(instruct_array[0]);
	if (!ofunction)
	{
		fprintf(
				stderr,
				"L%d: unknown instruction %s\n",
				globals.linenumber, instruct_array[0]);
		grbage_collectr();
		exit(EXIT_FAILURE);
	}
	if (instruct_array[1])
	{
		if (!isintinger(instruct_array[1]) && strcmp(instruct_array[0], "push") == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", globals.linenumber);
			grbage_collectr();
			exit(EXIT_FAILURE);
		}
		globals.oparg = atoi(instruct_array[1]);
	}
	else if ((strcmp(instruct_array[0], "push") == 0) && (!instruct_array[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", globals.linenumber);
		grbage_collectr();
		exit(EXIT_FAILURE);
	}
	ofunction(&globals.stk_top, globals.linenumber);
}
