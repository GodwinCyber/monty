#include "monty.h"

/**
 * pint - prints the element at the top of the stack
 * Description: i.e. the stack_top (topmost)
 * @stack_top: double pointer to stack_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void pint(stack_t **stack_top, unsigned int n)
{
	(void)n;
	if (*stack_top != NULL)
		printf("%d\n", (*stack_top)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", globals.linenumber);
		free(globals.linebuffer);
		free(globals.instruct_array);
		if (globals.stk_top)
			free_stk(globals.stk_top);
		fclose(globals.fp);
		exit(EXIT_FAILURE);
	}
}
