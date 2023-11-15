#include "monty.h"

/**
 * stack_length - determines the number of elements of the structure stack_s
 * @stack_top: the head of a structure of type 'struct stack_s'
 *
 * Return: the number of nodes in the list
 */
size_t stack_length(const stack_t *stack_top)
{
	size_t n = 0;
	stack_t *temporary;

	temporary = (stack_t *)stack_top;
	for (; temporary; temporary = temporary->next)
	{
		n++;
	}

	return (n);
}
