#include "monty.h"

/**
 * mod - calculates the modulus of dividing two elements of the stack
 * Description: i.e. the stack_top->next by stack_top
 * and stores the result in stack_top->next, popping stack_top
 * @stack_top: double pointer to stack_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void mod(stack_t **stack_top, unsigned int n)
{
	stack_t *temporary;
	(void)n;

	if (*stack_top != NULL)
	{
		temporary = *stack_top;
		if (temporary->next)
		{
			*stack_top = temporary->next;
			if (temporary->n == 0)
			{
				fprintf(stderr, "L%u: division by zero\n", n);
				grbage_collectr();
				exit(EXIT_FAILURE);
			}
			else
				(*stack_top)->n = (*stack_top)->n % temporary->n;
			(*stack_top)->prev = NULL;
			free(temporary);
		}
		else
		{
			fprintf(stderr, "L%u: can't mod, stack too short\n", n);
			grbage_collectr();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", n);
		grbage_collectr();
		exit(EXIT_FAILURE);
	}
}
