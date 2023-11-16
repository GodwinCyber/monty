#include "monty.h"

/**
 * isintinger - checks if str contains only characters 0 through 9.
 * @string: string to check.
 *
 * Return: 1 of str is numeric, 0 otherwise.
 */
int isintinger(char *string)
{
	int i;

	for (i = 0; string[i]; i++)
	{
		if (isdigit(string[i]) == 0)
		{
			return (0);
		}
	}

	return (1);
}
