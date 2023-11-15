#include "monty.h"

/**
 * pall - prints all elements of the structure stack_s
 * @stack_top: the head of a structure of type 'struct stack_s'
 * @n: file current line number.
 */
void pall(stack_t **stack_top, unsigned int n __attribute__((unused)))
{
	stack_t *stack_top_cpy = *stack_top;

	for (; stack_top_cpy; stack_top_cpy = (stack_top_cpy)->next)
	{
		printf("%d\n", (stack_top_cpy)->n);
	}
}
