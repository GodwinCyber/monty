#include "monty.h"

/**
 * swap - swaps the two element at the top of the stack
 * Description: i.e. the stack_top (topmost) and stack_top->next
 * @stack_top: double pointer to stack_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void swap(stack_t **stack_top, unsigned int n)
{
	stack_t *temporary, *thrd;
	(void)n;

	if (*stack_top != NULL)
	{
		temporary = *stack_top;
		if (temporary->next)
		{
			*stack_top = temporary->next;
			if (temporary->next->next)
			{
				thrd = temporary->next->next;
				thrd->prev = temporary;
				temporary->next = thrd;
			}
			else
			{
				temporary->next = NULL;
			}
			(*stack_top)->prev = NULL;
			(*stack_top)->next = temporary;
			temporary->prev = *stack_top;
		}
		else
		{
			fprintf(stderr, "L%u: can't swap, stack too short\n", n);
			grbage_collectr();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", n);
		grbage_collectr();
		exit(EXIT_FAILURE);
	}
}
