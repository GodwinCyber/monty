#include "monty.h"

/**
 * pstr - prints the string (of characters) in the stack from the top down
 * Description: i.e. treats the integers as an ascii values
 * if the integer is 0, not in the ascii table  or the stack is empty,
 * the function exits with an error
 * @stack_top: double pointer to stack_top(top) of stack
 * @n: line number
 * Return: Nothing
 */
void pstr(stack_t **stack_top, unsigned int n)
{
	stack_t *curr = *stack_top;
	(void)n;

	if (*stack_top != NULL)
	{
		while (curr != NULL)
		{
			if (curr->n < 1 || curr->n > 127)
				break;
			printf("%c", curr->n);
			curr = curr->next;
		}
	}
	printf("\n");
}
