#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * Description: i.e. the top element of the stack becomes the last one
 * and the second top element becomes the first one (the stack_top)
 * @stack_top: double pointer to stack_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void rotl(stack_t **stack_top, unsigned int n)
{
	stack_t *temporary, *last = *stack_top;
	(void)n;

	if (*stack_top != NULL && (*stack_top)->next)
	{
		temporary = (*stack_top)->next;

		while (last->next != NULL)
			last = last->next;

		last->next = *stack_top;
		(*stack_top)->prev = last;
		(*stack_top)->next = NULL;
		temporary->prev = NULL;
		*stack_top = temporary;
	}
}
