#include "monty.h"

/**
 * pchar - prints the character stored at the top of the stack
 * Description: i.e. treats the integer as an ascii value
 * if the integer is not in the ascii table - exits with an error
 * @stack_top: double pointer to stack_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void pchar(stack_t **stack_top, unsigned int n)
{
	(void)n;

	if (*stack_top != NULL)
	{
		if ((*stack_top)->n < 0 || (*stack_top)->n > 127)
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", globals.linenumber);
			grbage_collectr();
			exit(EXIT_FAILURE);
		}
		else
			printf("%c\n", (*stack_top)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", globals.linenumber);
		grbage_collectr();
		exit(EXIT_FAILURE);
	}
}
