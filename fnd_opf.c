#include "monty.h"

/**
 * find_opfunction - returns the function of the opcode represented by opstring.
 * @opstring: string representing a potentially available opcode.
 *
 * Return: pointer to the function corresponding to opstring, or NULL if no match.
 */
opfunc find_opfunction(char *opstring)
{
	int i = 0;
	static int on_queue;
	instruction_t oplist[] = {
		{"push", push}, {"pall", pall}, {"swap", swap}, {"pop", pop},
		{"sub", sub}, {"div", div_}, {"mul", mul}, {"mod", mod}, {"add", add},
		{"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
		{"stack", stack_}, {"queue", queue}, {"pint", pint}, {"nop", nop},
		{NULL, NULL},
	};

	if (strcmp(opstring, "queue") == 0)
		on_queue = 1;
	else if (strcmp(opstring, "stack") == 0)
		on_queue = 0;

	while (oplist[i].opcode != NULL)
	{
		if (strcmp(oplist[i].opcode, opstring) == 0)
		{
			if (strcmp(opstring, "push") == 0 && on_queue)
				return (push_queue);
			else
				return (oplist[i].f);
		}
		i++;
	}

	return (NULL);
}
