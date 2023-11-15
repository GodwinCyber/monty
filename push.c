#include "monty.h"

/**
 * push -  adds a new node at the beginning of a stack_t list.
 * @stack_top: a double pointer representing the address of the head of the list
 * @n: integer to initialize the new node with
 */
void push(stack_t **stack_top, unsigned int n)
{
	stack_t *new_node;

	(void)n;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(globals.linebuffer);
		free(globals.instruct_array);
		if (globals.stk_top)
			free_stk(globals.stk_top);
		fclose(globals.fp);
		exit(EXIT_FAILURE);
	}

	new_node->n = globals.oparg;
	new_node->next = *stack_top;
	new_node->prev = NULL;

	if (*stack_top)
	{
		(*stack_top)->prev = new_node;
	}
	*stack_top = new_node;
}
