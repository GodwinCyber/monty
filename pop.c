#include "monty.h"

/**
 * pop - deletes the head node of a stack_t linked list.
 * @stack_top: a pointer storing the address of the pointer to the list head
 * @n: unsigned int.
 */
void pop(stack_t **stack_top, unsigned int n __attribute__((unused)))
{
	stack_t *head_copy;

	if (!(*stack_top))
	{
		fprintf(
				stderr,
				"L%d: can't pop an empty stack\n",
				globals.linenumber);
		free(globals.linebuffer);
		free(globals.instruct_array);
		if (globals.stk_top)
			free_stk(globals.stk_top);
		fclose(globals.fp);
		exit(EXIT_FAILURE);
	}

	if (stack_length(*stack_top) != 0)
	{
		head_copy = *stack_top;

		*stack_top = (*stack_top)->next;
		if (*stack_top)
		{
			(*stack_top)->prev = NULL;
		}

		free(head_copy);
	}
}
