#include "monty.h"

/**
 * isintinger - checks if string contains only characters 0 through 9.
 * @string: stringing to check.
 *
 * Return: 1 of string is numeric, 0 otherwise.
 */
int isintinger(char *string)
{
	int i = 0, entry_flag = 0;

	if (string[0] == '-' || string[0] == '+')
	{
		i = 1;
	}

	for (; string[i]; i++)
	{
		entry_flag = 1;
		if (isdigit(string[i]) == 0)
		{
			return (0);
		}
	}

	if (!entry_flag)
	{
		return (0);
	}

	return (1);
}
