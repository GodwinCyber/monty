#include "monty.h"

/**
 * free_stk - frees a stack_t linked list
 * @stack_top: pointer to the first node of the list
 */
void free_stk(stack_t *stack_top)
{
	stack_t *temporary2, *temporary = stack_top;

	for (; temporary; temporary = temporary2)
	{
		temporary2 = temporary->next;
		free(temporary);
	}
}
