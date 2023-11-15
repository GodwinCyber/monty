#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * Description: i.e. the last element of the stack becomes the top one
 * and the stack_top (top element) becomes the second one
 * @stack_top: double pointer to stack_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void rotr(stack_t **stack_top, unsigned int n)
{
	stack_t *last = *stack_top;
	(void)n;

	if (*stack_top != NULL && (*stack_top)->next)
	{
		while (last->next != NULL)
			last = last->next;

		last->next = *stack_top;
		(last->prev)->next = NULL;
		last->prev = NULL;
		(*stack_top)->prev = last;
		*stack_top = last;
	}
}
