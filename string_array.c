#include "monty.h"

/**
 * str_array - collects token strings into an array of strings.
 * @string: string to tokenize.
 * @delimiter: string made up of delimiter characters.
 *
 * Description: the pointers in the returned array
 * are simply addresses in str, not some malloc'd addresses.
 * Hence, you should only conduct L0 free.
 * Return: a NULL-teminated array of token strings.
 */
char **str_array(char *string, const char *delimiter)
{
	char **string_ar, *token;
	int i, bsize = sizeof(char *), bsize_total = bsize, old_bsize = 0;

	string_ar = malloc(bsize);
	if (!string_ar)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(string, delimiter);
	if (!token)
	{
		string_ar[0] = NULL;
		return (string_ar);
	}
	i = 0;
	while (token)
	{
		string_ar[i] = token;
		i++;
		token = strtok(NULL, delimiter);

		handler_realloc(&(string_ar), i, bsize, &old_bsize, &bsize_total);

		if (!token)
		{
			string_ar[i] = NULL;
			break;
		}
	}

	return (string_ar);
}
