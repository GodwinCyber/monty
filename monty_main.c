#include "monty.h"

globals_t globals;


/**
 * main - driver for the Monty ByteCode interpreter.
 * @argc: number of args passed to the interpreter.
 * @argv: array of command-line args.
 *
 * Return: always 0.
 */
int main(int argc, char *argv[])
{
	int read;
	size_t buffer_size = 0;

	init_the_globals();
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	globals.fp = fopen(argv[1], "r");
	if (!globals.fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read = getline(&globals.linebuffer, &buffer_size, globals.fp);
	while (read != -1)
	{
		globals.linenumber++;
		globals.instruct_array = str_array(globals.linebuffer, "\a\r \t\n");
		if (!(globals.instruct_array)[0] || (globals.instruct_array)[0][0] == '#')
		{
			goto nextline;
		}
		perform_operation(globals.instruct_array);
nextline:
		free(globals.linebuffer);
		globals.linebuffer = NULL;
		free(globals.instruct_array);
		read = getline(&globals.linebuffer, &buffer_size, globals.fp);
	}
	free(globals.linebuffer);
	if (globals.stk_top)
		free_stk(globals.stk_top);
	fclose(globals.fp);
	return (0);
}
