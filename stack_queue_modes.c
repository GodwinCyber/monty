#include "monty.h"

/**
 * queue - does nothing to the top of the stack
 * @stack_top: double pointer to stack_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void queue(stack_t **stack_top, unsigned int n)
{
	(void)n;
	(void)stack_top;
}

/**
 * stack_ - does nothing to the top of the stack
 * @stack_top: double pointer to stack_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void stack_(stack_t **stack_top, unsigned int n)
{
	(void)n;
	(void)stack_top;
}

/**
 * push_queue - (an opcode) pushes an element to the stack's rear(stack_tail)
 * @stack_top: double pointer to stack_top of stack
 * @n: integer argument
 * Description: adds new element to the stack_top of list
 * Return: Nothing
 */
void push_queue(stack_t **stack_top, unsigned int n)
{
	stack_t *new_node, *stack_tail = *stack_top;
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
	new_node->next = NULL;

	if (stack_tail != NULL)
	{
		while (stack_tail->next != NULL)
			stack_tail = stack_tail->next;
		new_node->prev = stack_tail;
		stack_tail->next = new_node;
	}
	else
	{
		new_node->prev = NULL;
		*stack_top = new_node;
	}
}
